#include "main_state.h"

#include <src/gl/shader.h>
#include <src/gl/mesh.h>
#include <src/entities/camera.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

MainState::MainState() {
	shader_ = std::make_unique<Shader>("data/shaders/main.vert", "data/shaders/main.frag");
	mesh_ = std::make_unique<Mesh>();
	camera_ = std::make_unique<Camera>(640.0f / 480.0f, 90.0f);
	camera_->SetPosition(glm::vec3{ 0.0f, 0.0f, 1.0f });
}

MainState::~MainState() {

}

void MainState::Update(float delta_time) {
	camera_->Update();
}

void MainState::Render() {
	auto model_mat = glm::translate(glm::mat4(1.0f), glm::vec3(0.2f, 0.1f, 0.0f));
	auto pvm_mat = camera_->GetProjectionViewMatrix() * model_mat;

	glEnable(GL_MULTISAMPLE);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glViewport(0, 0, 640, 480);

	glClearColor(0.2f, 0.0f, 0.2f, 1.0f);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	shader_->Use();
	shader_->SetMatrix4("uPVMMat", pvm_mat);
	mesh_->Bind();
	mesh_->Draw();
}
