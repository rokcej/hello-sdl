#include "camera.h"

#include <engine/managers/window_manager.h>
#include <glm/gtc/matrix_transform.hpp>

namespace engine {

Camera::Camera(float fov) {
	fov_ = fov;

	UpdateProjectionMatrix();
	window_size_changed_delegate_id_ = pWindowManager.GetMainWindow()->OnSizeChangedDelegate += [this] {
		UpdateProjectionMatrix();
	};
}

Camera::~Camera() {
	pWindowManager.GetMainWindow()->OnSizeChangedDelegate -= window_size_changed_delegate_id_;
}

void Camera::Update() {
	const glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	view_mat_ = glm::lookAt(GetPosition(), GetPosition() + GetForward(), up);
	proj_view_mat_ = proj_mat_ * view_mat_;
}

const glm::mat4& Camera::GetProjectionViewMatrix() const {
	return proj_view_mat_;
}

void Camera::UpdateProjectionMatrix() {
	const Window* window = pWindowManager.GetMainWindow();
	const float aspect_ratio = static_cast<float>(window->GetWidth()) / static_cast<float>(window->GetHeight());
	proj_mat_ = glm::perspective(glm::radians(fov_), aspect_ratio, 0.1f, 100.0f);
}

} // namespace engine
