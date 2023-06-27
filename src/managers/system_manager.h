#pragma once

#include "manager.h"

class SystemManager : public Manager {
protected:
	bool OnCreate() override;
	void OnDestroy() override;

};

extern SystemManager pSystemManager;
