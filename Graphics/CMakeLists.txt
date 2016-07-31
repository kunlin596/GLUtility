find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(. GRAPHICS_SRC_LIST)
add_library(Graphics SHARED ${GRAPHICS_SRC_LIST})
target_link_libraries(Graphics
    ${GLEW_LIBRARIES}
    ${OPENGL_LIBRARIES})
