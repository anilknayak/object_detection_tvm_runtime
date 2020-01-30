add_library(face_segmentation face_segmentation.cxx)

# state that anybody linking to us needs to include the current source dir
# to find face_segmentation.h, while we don't.
target_include_directories(face_segmentation
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# define the symbol stating we are using the declspec(dllexport) when
# building on windows
target_compile_definitions(face_segmentation PRIVATE "EXPORTING_FACESEGMENTATION")

# install rules
install(TARGETS face_segmentation DESTINATION lib)
install(FILES face_segmentation.h DESTINATION include)