#pragma once

#include <src/entities/entity.h>
#include <glm/glm.hpp>

class Camera : public Entity {
public:
	Camera(float aspect_ratio, float fov);

	void Update(float delta_time) override;

	const glm::mat4& GetProjectionViewMatrix() const;

private:
	glm::mat4 proj_mat_;
	glm::mat4 view_mat_;
	glm::mat4 proj_view_mat_;

	float fov_;
	float aspect_ratio_;

};