#include <src/gl/shader.h>
#include <src/gl/mesh.h>
#include <src/entities/camera.h>
#include <src/window.h>
#include <SDL.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

int main(int argc, char* args[]) {
	Window window;
	if (!window.Init("Hello SDL", 640, 480)) {
		std::cerr << "Error initializing window" << std::endl;
		return 1;
	}

	glEnable(GL_MULTISAMPLE);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glViewport(0, 0, 640, 480);

	Shader shader{"data/shaders/main.vert", "data/shaders/main.frag"};
	Mesh mesh;
	Camera camera{ (float)window.GetWidth() / window.GetHeight(), 90.0f};
	camera.SetPosition(glm::vec3{ 0.0f, 0.0f, 1.0f });

	bool is_running = true;
	while (is_running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				is_running = false;
			}
		}

		camera.Update(0.0f);

		auto model_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.2f, 0.1f, 0.0f));
		auto pvm_mat = camera.GetProjectionViewMatrix() * model_mat;

		glClearColor(0.2f, 0.0f, 0.2f, 1.0f);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		shader.Use();
		shader.SetMatrix4("uPVMMat", pvm_mat);
		mesh.Bind();
		mesh.Draw();

		window.SwapBuffer();
		SDL_Delay(10); // Poor man's FPS limiter
	}

	return 0;
}
