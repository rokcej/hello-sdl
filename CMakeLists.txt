cmake_minimum_required(VERSION 3.13)

project(hello-sdl)

add_executable(hello-sdl "src/main.cpp" "src/gl/shader.h" "src/gl/shader.cpp" "src/utils/file.h" "src/utils/file.cpp"  "src/gl/mesh.cpp" "src/gl/mesh.h" "src/entities/entity.h" "src/entities/entity.cpp" "src/entities/camera.h" "src/entities/camera.cpp")

target_compile_features(hello-sdl PUBLIC cxx_std_17)

# Put library DLLs into the same folder as the executable
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(lib/SDL)
add_subdirectory(lib/glad)
add_subdirectory(lib/glm)

target_include_directories(hello-sdl PRIVATE
	.
)

target_link_libraries(hello-sdl PRIVATE
	SDL2::SDL2main
	SDL2::SDL2 
	glad
	glm
)
