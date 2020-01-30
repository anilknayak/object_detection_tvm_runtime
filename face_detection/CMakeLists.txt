add_library(face_detection face_detection.cxx)

# state that anybody linking to us needs to include the current source dir
# to find face_detection.h, while we don't.
target_include_directories(face_detection
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# define the symbol stating we are using the declspec(dllexport) when
# building on windows
target_compile_definitions(face_detection PRIVATE "EXPORTING_FACEDETECTION")

# install rules
install(TARGETS face_detection DESTINATION lib)
install(FILES face_detection.h DESTINATION include)