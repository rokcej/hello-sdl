#include "entity.h"

void Entity::SetPosition(const glm::vec3& position) {
	position_ = position;
}

void Entity::SetRotation(const glm::vec3& rotation) {
	rotation_ = rotation;

	const float cos_rot_x = std::cos(rotation_.x);
	forward_.x = -std::sin(rotation_.y) * cos_rot_x;
	forward_.y = +std::sin(rotation_.x);
	forward_.z = -std::cos(rotation_.y) * cos_rot_x;
}

const glm::vec3& Entity::GetPosition() const {
	return position_;
}

const glm::vec3& Entity::GetRotation() const {
	return rotation_;
}

const glm::vec3& Entity::GetForward() const {
	return forward_;
}
