add_library(face_race_ethnicity face_race_ethnicity.cxx)

# state that anybody linking to us needs to include the current source dir
# to find face_race_ethnicity.h, while we don't.
target_include_directories(face_race_ethnicity
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# define the symbol stating we are using the declspec(dllexport) when
# building on windows
target_compile_definitions(face_race_ethnicity PRIVATE "EXPORTING_FACERACE")

# install rules
install(TARGETS face_race_ethnicity DESTINATION lib)
install(FILES face_race_ethnicity.h DESTINATION include)