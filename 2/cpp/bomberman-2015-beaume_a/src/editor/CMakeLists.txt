add_definitions("-Wall -Wextra")
if (CMAKE_BUILD_TYPE MATCHES "Debug")
  add_definitions("-g3 -DDDEBUG_ENABLE")
elseif (CMAKE_BUILD_TYPE MATCHES "Release")
  add_definitions("-Werror")
endif()

include_directories(${EDITOR_INC_DIRS})

set(QT_USE_QT3SUPPORT TRUE)   
set(QT_USE_QTXML TRUE)

find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})

qt4_add_resources(SAMPLE_RC_SRCS ${SAMPLE_RCS})

qt4_wrap_ui(SAMPLE_UI_HDRS ${SAMPLE_UIS})

qt4_wrap_cpp(SAMPLE_MOC_SRCS ${SAMPLE_MOC_HDRS})

include_directories(${CMAKE_BINARY_DIR})

add_executable(${EDITOR_BIN_NAME} ${SAMPLE_SRCS} ${SAMPLE_MOC_SRCS} ${SAMPLE_RC_SRCS} ${SAMPLE_UI_HDRS})

target_link_libraries(${EDITOR_BIN_NAME} ${QT_LIBRARIES})
