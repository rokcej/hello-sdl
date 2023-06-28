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

void ManagerSystem::Update() {
	for (auto& manager : managers_) {
		manager->OnUpdate();
	}
}

void ManagerSystem::Register(Manager* manager) {
	managers_.push_back(manager);
}

void ManagerSystem::Quit() {
	is_quitting_ = true;
}

bool ManagerSystem::IsQuitting() const {
	return is_quitting_;
}
