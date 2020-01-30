add_library(face_emotion face_emotion.cxx)

# state that anybody linking to us needs to include the current source dir
# to find face_emotion.h, while we don't.
target_include_directories(face_emotion
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# define the symbol stating we are using the declspec(dllexport) when
# building on windows
target_compile_definitions(face_emotion PRIVATE "EXPORTING_FACEEMOTION")

# install rules
install(TARGETS face_emotion DESTINATION lib)
install(FILES face_emotion.h DESTINATION include)