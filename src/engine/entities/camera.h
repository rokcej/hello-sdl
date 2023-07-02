#pragma once

#include <engine/entities/entity.h>
#include <glm/glm.hpp>

namespace engine {

class Camera : public Entity {
public:
	Camera(float aspect_ratio, float fov);

	void Update();

	const glm::mat4& GetProjectionViewMatrix() const;

private:
	glm::mat4 proj_mat_;
	glm::mat4 view_mat_;
	glm::mat4 proj_view_mat_;

	float fov_;
	float aspect_ratio_;

};

} // namespace engine