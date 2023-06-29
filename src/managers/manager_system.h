#pragma once

#include <src/utils/singleton.h>
#include <vector>

class Manager;

class ManagerSystem : public Singleton<ManagerSystem>{
	friend class Manager;

public:
	bool Create();
	void Destroy();
	void Update();

	void Quit();
	bool IsQuitting() const;

private:
	void Register(Manager* manager);

private:
	std::vector<Manager*> managers_;
	bool is_quitting_ = false;

};
