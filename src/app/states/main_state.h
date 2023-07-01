#pragma once

#include "state.h"
#include <memory>

namespace engine {
	class Shader;
	class Mesh;
	class Camera;
	class Entity;
} // namespace engine

namespace app {

class MainState : public State {
public:
	MainState();
	~MainState();

	void Update(float delta_time) override;
	void Render() override;

private:
	std::unique_ptr<engine::Shader> shader_;
	std::unique_ptr<engine::Mesh> mesh_;
	std::unique_ptr<engine::Camera> camera_;
	std::unique_ptr<engine::Entity> object_;

	float rotation_speed_ = 1.0f;

};

} // namespace app
