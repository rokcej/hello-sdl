#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace engine {

Camera::Camera(float aspect_ratio, float fov) {
	aspect_ratio_ = aspect_ratio;
	fov_ = fov;

	proj_mat_ = glm::perspective(glm::radians(fov_), aspect_ratio_, 0.1f, 100.0f);
}

void Camera::Update() {
	const glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	view_mat_ = glm::lookAt(GetPosition(), GetPosition() + GetForward(), up);
	proj_view_mat_ = proj_mat_ * view_mat_;
}

const glm::mat4& Camera::GetProjectionViewMatrix() const {
	return proj_view_mat_;
}

} // namespace engine
