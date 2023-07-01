#pragma once

#include "manager.h"

namespace engine {

class SystemManager : public Manager {
public:
	void Sleep(unsigned int milliseconds);

protected:
	bool OnCreate() override;
	void OnDestroy() override;
	void OnUpdate() override;

private:
	void PollEvents();

};

extern SystemManager pSystemManager;

} // namespace engine
