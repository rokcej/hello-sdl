#pragma once

#include <engine/entities/entity.h>
#include <engine/utils/delegate.h>
#include <glm/glm.hpp>

namespace engine {

class Camera : public Entity {
public:
	Camera(float fov);
	~Camera();

	void Update();

	const glm::mat4& GetProjectionViewMatrix() const;

private:
	void UpdateProjectionMatrix();

private:
	glm::mat4 proj_mat_;
	glm::mat4 view_mat_;
	glm::mat4 proj_view_mat_;

	float fov_;

	DelegateId window_size_changed_delegate_id_;

};

} // namespace engine
