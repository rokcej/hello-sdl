#pragma once

class State {
public:
	virtual void Update(float delta_time) = 0;
	virtual void Render() = 0;

};
