#include "manager.h"

#include "manager_system.h"

Manager::Manager() {
	ManagerSystem::GetInstance().Register(this);
}
