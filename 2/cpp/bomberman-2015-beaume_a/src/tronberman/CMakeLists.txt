if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
  set(CMAKE_CXX_FLAGS		"-Wall -Wextra")
  set(CMAKE_CXX_FLAGS_DEBUG	"-g3 -DDEBUG_ENABLE")
  set(CMAKE_CXX_FLAGS_RELEASE   "-Werror")
endif ()

if (CMAKE_HOST_LINUX AND CMAKE_64B_WORKSTATION)
  set(IS_GRAPHIC_INTERFACE 1)
else ()
  set(IS_GRAPHIC_INTERFACE 0)
endif ()

if (IS_GRAPHIC_INTERFACE)
  add_definitions(-DGRAPHIC_INTERFACE=1)

  cmake_policy(SET CMP0015 NEW)
  link_directories(
    ${LIBS_DIR}/gdl_gl/
    ${LIBS_DIR}/fmod/
  )
else ()
  add_definitions(-DGRAPHIC_INTERFACE=0)
endif ()

include_directories(${GAME_INC_DIRS})

add_executable(${GAME_BIN_NAME} ${GAME_SRC_FILES})

if (IS_GRAPHIC_INTERFACE)
  if (CMAKE_BUILD_TYPE MATCHES "Debug")
    target_link_libraries(${GAME_BIN_NAME} gdl_gl-d)
  else ()
    target_link_libraries(${GAME_BIN_NAME} gdl_gl)
  endif ()
  target_link_libraries(${GAME_BIN_NAME} GL)
  target_link_libraries(${GAME_BIN_NAME} GLU)
  target_link_libraries(${GAME_BIN_NAME} fmod)
  include_directories(
    ${LIBS_DIR}/gdl_gl/include/
    ${LIBS_DIR}/fmod/include/
  )
endif ()

target_link_libraries(${GAME_BIN_NAME} pthread)
