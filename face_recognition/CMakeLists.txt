add_library(face_recognition face_recognition.cxx)

# state that anybody linking to us needs to include the current source dir
# to find face_recognition.h, while we don't.
target_include_directories(face_recognition
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# define the symbol stating we are using the declspec(dllexport) when
# building on windows
target_compile_definitions(face_recognition PRIVATE "EXPORTING_FACERECOGNITION")

# install rules
install(TARGETS face_recognition DESTINATION lib)
install(FILES face_recognition.h DESTINATION include)