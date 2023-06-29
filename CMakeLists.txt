cmake_minimum_required(VERSION 3.13)

project(hello-sdl)

add_executable(hello-sdl "src/main.cpp" "src/gl/shader.h" "src/gl/shader.cpp" "src/utils/file.h" "src/utils/file.cpp"  "src/gl/mesh.cpp" "src/gl/mesh.h" "src/entities/entity.h" "src/entities/entity.cpp" "src/entities/camera.h" "src/entities/camera.cpp" "src/window.h" "src/window.cpp" "src/utils/timer.h" "src/utils/timer.cpp" "src/states/main_state.cpp" "src/states/main_state.h" "src/states/state.h" "src/managers/manager.h" "src/managers/window_manager.h" "src/managers/window_manager.cpp" "src/managers/manager_system.h" "src/managers/manager_system.cpp" "src/utils/singleton.h" "src/managers/manager.cpp" "src/managers/system_manager.cpp" "src/managers/system_manager.h" "src/engine/debug.cpp" "src/engine/debug.h" "src/engine.h")

target_compile_features(hello-sdl PUBLIC cxx_std_17)
target_compile_options(hello-sdl PUBLIC
	$<$<CXX_COMPILER_ID:MSVC>:/W3 /WX>
	$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

target_compile_definitions(hello-sdl PUBLIC
	$<$<CONFIG:DEBUG>:BUILD_DEBUG>
	$<$<CONFIG:RELEASE>:BUILD_RELEASE>
)

# Put library DLLs into the same folder as the executable
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(lib/SDL)
add_subdirectory(lib/glad)
add_subdirectory(lib/glm)
add_subdirectory(lib)

target_include_directories(hello-sdl
	PRIVATE .
)

target_link_libraries(hello-sdl
	PRIVATE SDL2::SDL2main SDL2::SDL2 glad glm imgui
)
