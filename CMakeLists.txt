cmake_minimum_required(VERSION 3.13)

project(hello-sdl)

add_executable(hello-sdl "src/main.cpp" "src/engine/gl/shader.h" "src/engine/gl/shader.cpp" "src/engine/utils/file.h" "src/engine/utils/file.cpp"  "src/engine/gl/mesh.cpp" "src/engine/gl/mesh.h" "src/engine/entities/entity.h" "src/engine/entities/entity.cpp" "src/engine/entities/camera.h" "src/engine/entities/camera.cpp" "src/engine/video/window.h" "src/engine/video/window.cpp" "src/engine/utils/timer.h" "src/engine/utils/timer.cpp" "src/app/states/main_state.cpp" "src/app/states/main_state.h" "src/app/states/state.h" "src/engine/managers/manager.h" "src/engine/managers/window_manager.h" "src/engine/managers/window_manager.cpp" "src/engine/managers/manager_system.h" "src/engine/managers/manager_system.cpp" "src/engine/utils/singleton.h" "src/engine/managers/manager.cpp" "src/engine/managers/system_manager.cpp" "src/engine/managers/system_manager.h" "src/engine/debug.cpp" "src/engine/debug.h"  "src/engine/utils/string.h" "src/engine/utils/string.cpp" "src/engine/utils/delegate.cpp" "src/engine/utils/delegate.h")

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
	PRIVATE src
)

target_link_libraries(hello-sdl
	PRIVATE SDL2::SDL2main SDL2::SDL2 glad glm imgui
)
