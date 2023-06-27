#pragma once

#include "src/utils/singleton.h"
#include <vector>

class Manager;

class ManagerSystem : public Singleton<ManagerSystem>{
	friend class Manager;

public:
	bool Create();
	void Destroy();

private:
	void Register(Manager* manager);

private:
	std::vector<Manager*> managers_;

};
