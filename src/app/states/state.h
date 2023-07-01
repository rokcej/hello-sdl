#pragma once

namespace app {

class State {
public:
	virtual void Update(float delta_time) = 0;
	virtual void Render() = 0;

};

} // namespace app
