add_library(face_age_gender face_age_gender.cxx)

# state that anybody linking to us needs to include the current source dir
# to find face_age_gender.h, while we don't.
target_include_directories(face_age_gender
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# define the symbol stating we are using the declspec(dllexport) when
# building on windows
target_compile_definitions(face_age_gender PRIVATE "EXPORTING_FACEAGEGENDER")

# install rules
install(TARGETS face_age_gender DESTINATION lib)
install(FILES face_age_gender.h DESTINATION include)