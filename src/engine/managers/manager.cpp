#include "manager.h"

#include "manager_system.h"

namespace engine {

Manager::Manager() {
	ManagerSystem::GetInstance().Register(this);
}

} // namespace engine
