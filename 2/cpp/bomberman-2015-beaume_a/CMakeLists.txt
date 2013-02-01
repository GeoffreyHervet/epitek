######
######
# Sources
######

########
# Client
#
#  `- binary name
set(GAME_BIN_NAME "tronberman")
#  `- directory
set(GAME_DIR "./src/tronberman")
#  `- source dir
set(GAME_SRC_DIR ".")
#  `- source files
set(GAME_SRC_FILES
  "${GAME_SRC_DIR}/main.cpp"
  "${GAME_SRC_DIR}/myMath.cpp"
  "${GAME_SRC_DIR}/Interp.cpp"
  "${GAME_SRC_DIR}/Core.cpp"
  "${GAME_SRC_DIR}/Map.cpp"
  "${GAME_SRC_DIR}/MapGraph.cpp"
  "${GAME_SRC_DIR}/IniFile.cpp"
  "${GAME_SRC_DIR}/Log/Log.cpp"
  "${GAME_SRC_DIR}/Sound/FmodManager.cpp"
  "${GAME_SRC_DIR}/Config.cpp"
  "${GAME_SRC_DIR}/Error.cpp"
  "${GAME_SRC_DIR}/MyGame.cpp"
  "${GAME_SRC_DIR}/Skybox.cpp"
  "${GAME_SRC_DIR}/Camera.cpp"
  "${GAME_SRC_DIR}/Lights.cpp"
  "${GAME_SRC_DIR}/Bombs.cpp"
  "${GAME_SRC_DIR}/Cube.cpp"
  "${GAME_SRC_DIR}/setMateriel.cpp"
  "${GAME_SRC_DIR}/Particle.cpp"
  "${GAME_SRC_DIR}/ParticlesEngine.cpp"
  "${GAME_SRC_DIR}/ParticlesBlast.cpp"
  "${GAME_SRC_DIR}/Player.cpp"
  "${GAME_SRC_DIR}/Players.cpp"
  "${GAME_SRC_DIR}/BrainIA.cpp"
  "${GAME_SRC_DIR}/BrainReal.cpp"
  "${GAME_SRC_DIR}/DirectoryReader.cpp"
  "${GAME_SRC_DIR}/Blasts.cpp"
  "${GAME_SRC_DIR}/InterpVect.cpp"
  "${GAME_SRC_DIR}/Content.cpp"
  "${GAME_SRC_DIR}/Menu/AMenu.cpp"
  "${GAME_SRC_DIR}/Menu/MenuGame.cpp"
  "${GAME_SRC_DIR}/Menu/CreditsView.cpp"
  "${GAME_SRC_DIR}/Menu/Main.cpp"
  "${GAME_SRC_DIR}/Menu/Play.cpp"
  "${GAME_SRC_DIR}/Menu/Loader.cpp"
  "${GAME_SRC_DIR}/Menu/Items/FastGame.cpp"
  "${GAME_SRC_DIR}/Menu/Items/Quit.cpp"
  "${GAME_SRC_DIR}/Menu/Items/Zlock.cpp"
  "${GAME_SRC_DIR}/Menu/Items/PrePlay.cpp"
  "${GAME_SRC_DIR}/Menu/Items/LoadGame.cpp"
  "${GAME_SRC_DIR}/Menu/Items/Credits.cpp"
  "${GAME_SRC_DIR}/Menu/Items/Number.cpp"
  "${GAME_SRC_DIR}/Menu/Items/ItemMap.cpp"
  "${GAME_SRC_DIR}/Menu/Items/ItemSave.cpp"
  "${GAME_SRC_DIR}/Menu/Items/SaveGame.cpp"
  "${GAME_SRC_DIR}/Menu/Items/Resume.cpp"
  "${GAME_SRC_DIR}/Menu/Items/Restart.cpp"
  "${GAME_SRC_DIR}/Menu/Items/BackToMain.cpp"
)
#  `- include directories
set(GAME_INC_DIRS
  "./"
  "./Menu/Items/"
  "./Menu/"
  "./Log/"
  "./Sound/"
)

########
# Editor
#
#  `- binary name
set(EDITOR_BIN_NAME "editor")
#  `- directory
set(EDITOR_DIR "./src/editor")
#  `- source dir
set(EDITOR_SRC_DIR "./src")
#  `- source files
set(SAMPLE_SRCS
  "${EDITOR_SRC_DIR}/main.cpp"
  "${EDITOR_SRC_DIR}/Document.cpp"
  "${EDITOR_SRC_DIR}/MainWindow.cpp"
  "${EDITOR_SRC_DIR}/MapView.cpp"
  "${EDITOR_SRC_DIR}/NewFileDialog.cpp"
)
#  `- qt moc files
set(SAMPLE_MOC_HDRS
  "include/Document.hpp"
  "include/MainWindow.hpp"
  "include/MapView.hpp"
)
#  `- qt qrc file
set(SAMPLE_RCS
  "editor.qrc"
)
#  `- include directories
set(EDITOR_INC_DIRS
  "./include/"
)

########
# Libraries directory
#
set(LIBS_DIR "${CMAKE_SOURCE_DIR}/libs")

####################################################
# PLEASE DO NOT CHANGE ANYTHING UNDER THIS WARNING #
####################################################

######
######
# Project Definition
######

cmake_minimum_required(VERSION 2.6)
project(Bomberman)

######
######
# Configuration
######
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

######
######
# Portability
######

# Linux
if (CMAKE_SYSTEM_NAME STREQUAL Linux)
  set(CMAKE_HOST_LINUX 1)
endif ()

# Mac OSX - Clang++
if (CMAKE_HOST_APPLE AND CMAKE_GENERATOR MATCHES "Unix Makefiles")
  set(CMAKE_COMPILER_IS_CLANGXX 1)
endif ()

# Detect 32/64 Bits
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(CMAKE_32B_WORKSTATION 0)
  set(CMAKE_64B_WORKSTATION 1) # 64 bits
else ()
  set(CMAKE_32B_WORKSTATION 1) # 32 bits
  set(CMAKE_64B_WORKSTATION 0)
endif ()

######
######
# Client and Server CMakeLists.txt
######

cmake_policy(SET CMP0013 NEW)
add_subdirectory(${GAME_DIR})
add_subdirectory(${EDITOR_DIR})
