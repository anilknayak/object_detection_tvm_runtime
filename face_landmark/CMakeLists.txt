add_library(face_landmark face_landmark.cxx)

# state that anybody linking to us needs to include the current source dir
# to find face_landmark.h, while we don't.
target_include_directories(face_landmark
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# define the symbol stating we are using the declspec(dllexport) when
# building on windows
target_compile_definitions(face_landmark PRIVATE "EXPORTING_FACELANDMARK")

# install rules
install(TARGETS face_landmark DESTINATION lib)
install(FILES face_landmark.h DESTINATION include)