#pragma once

#include "state.h"
#include <memory>

class Shader;
class Mesh;
class Camera;

class MainState : public State {
public:
	MainState();
	~MainState();

	void Update(float delta_time) override;
	void Render() override;

private:
	std::unique_ptr<Shader> shader_;
	std::unique_ptr<Mesh> mesh_;
	std::unique_ptr<Camera> camera_;

};
