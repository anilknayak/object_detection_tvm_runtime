# https://cmake.org/cmake/help/latest/guide/tutorial/index.html

cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(face_analysis VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
SET(HOME_TVM /home/anil/face_analysis/nnvm/tvm)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

INCLUDE_DIRECTORIES(${HOME_TVM}/include)
INCLUDE_DIRECTORIES(${HOME_TVM}/dmlc-core/include)
INCLUDE_DIRECTORIES(${HOME_TVM}/dlpack/include)
#find_package(OPENCV REQUIRED)
#INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

list(APPEND EXTRA_LIBS ${CMAKE_DL_LIBS})

# Enable all the libraries
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
option(USE_FACEDETECTION "Use face detection libraries" OFF)
option(USE_FACEAGEGENDER "Use face age and gender libraries" OFF)
option(USE_FACEDIZZINESS "Use face dizziness libraries" OFF)
option(USE_FACELANDMARK "Use face landmark libraries" OFF)
option(USE_FACERACE "Use face race libraries" OFF)
option(USE_FACERECOGNITION "Use face recognition libraries" OFF)
option(USE_FACESEGMENTATION "Use face segmentation libraries" OFF)
option(USE_FACEEMOTION "Use face emotion libraries" OFF)


# configure a header file to pass some of the CMake settings
# to the source code
configure_file(face_analysis_config.h.in face_analysis_config.h)

# add the subdirectory libraries
if(USE_FACEDETECTION)
  add_subdirectory(face_detection)
  list(APPEND EXTRA_LIBS face_detection)
endif()

# add the executable
add_executable(face_analysis tvm_runtime_pack.cc face_analysis.cxx)

target_link_libraries(face_analysis PUBLIC ${EXTRA_LIBS})

target_include_directories(face_analysis PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

install(TARGETS face_analysis DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/face_analysis_config.h"
  DESTINATION include
  )