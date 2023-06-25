# ---- ImGui ---- #
add_library(imgui
	# The core of Dear ImGui is self-contained within a few platform-agnostic files which you can easily compile in your application/engine.
	# They are all the files in the root folder of the repository (imgui*.cpp, imgui*.h).
	imgui/imgui.cpp
	imgui/imgui.h
	imgui/imgui_demo.cpp
	imgui/imgui_draw.cpp
	imgui/imgui_internal.h
	imgui/imgui_tables.cpp
	imgui/imgui_widgets.cpp
	# Backends for a variety of graphics API and rendering platforms are provided in the backends/ folder.
	imgui/backends/imgui_impl_sdl2.cpp
	imgui/backends/imgui_impl_sdl2.h
	imgui/backends/imgui_impl_opengl3.cpp
	imgui/backends/imgui_impl_opengl3.h
)
target_include_directories(imgui PUBLIC imgui)
target_link_libraries(imgui PUBLIC SDL2::SDL2)
