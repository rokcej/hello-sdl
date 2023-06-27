#include "manager_system.h"

#include "manager.h"

bool ManagerSystem::Create() {
	for (auto& manager : managers_) {
		if (!manager->OnCreate()) {
			return false;
		}
	}
	return true;
}

void ManagerSystem::Destroy() {
	for (auto& manager : managers_) {
		manager->OnDestroy();
	}
}

void ManagerSystem::Register(Manager* manager) {
	managers_.push_back(manager);
}
