#include "main_state.h"

#include <src/gl/shader.h>
#include <src/gl/mesh.h>
#include <src/entities/camera.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <imgui.h>

MainState::MainState() {
	shader_ = std::make_unique<Shader>("assets/shaders/main.vert", "assets/shaders/main.frag");
	mesh_ = std::make_unique<Mesh>();
	camera_ = std::make_unique<Camera>(640.0f / 480.0f, 90.0f);
	camera_->SetPosition(glm::vec3{ 0.0f, 0.0f, 2.0f });
	object_ = std::make_unique<Entity>();
}

MainState::~MainState() {

}

void MainState::Update(float delta_time) {
	camera_->Update();

	auto rot = object_->GetRotation();
	rot.y += delta_time * rotation_speed_;
	object_->SetRotation(rot);

	ImGui::Begin("Object controls");
	ImGui::SliderFloat("Rotation speed", &rotation_speed_, 0.1f, 10.0f);
	ImGui::End();
}

void MainState::Render() {
	glm::mat4 model_mat{ 1.0f };
	model_mat = glm::translate(model_mat, object_->GetPosition());
	model_mat = glm::rotate(model_mat, object_->GetRotation().y, glm::vec3{ 0.0f, 1.0f, 0.0f });
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
