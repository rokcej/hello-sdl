#pragma once

#include <glm/glm.hpp>

class Entity {
public:
	Entity() = default;

	void SetPosition(const glm::vec3& position);
	void SetRotation(const glm::vec3& rotation);
	const glm::vec3& GetPosition() const;
	const glm::vec3& GetRotation() const;
	const glm::vec3& GetForward() const;

private:
	glm::vec3 position_{ 0.0f, 0.0f, 0.0f };
	glm::vec3 rotation_{ 0.0f, 0.0f, 0.0f };
	glm::vec3 forward_{ 0.0f, 0.0f, -1.0f };

};
