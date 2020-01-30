add_library(face_dizziness face_dizziness.cxx)

# state that anybody linking to us needs to include the current source dir
# to find face_dizziness.h, while we don't.
target_include_directories(face_dizziness
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# define the symbol stating we are using the declspec(dllexport) when
# building on windows
target_compile_definitions(face_dizziness PRIVATE "EXPORTING_FACEDIZZINESS")

# install rules
install(TARGETS face_dizziness DESTINATION lib)
install(FILES face_dizziness.h DESTINATION include)