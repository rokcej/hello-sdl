#pragma once

namespace engine {

// TODO: Allow only one instance of each manager

class Manager {
	friend class ManagerSystem;

public:
	Manager();
	virtual ~Manager() = default;

protected:
	virtual bool OnCreate() { return true; };
	virtual void OnDestroy() {};
	virtual void OnUpdate() {};

};

} // namespace engine
