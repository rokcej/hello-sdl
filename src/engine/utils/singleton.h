#pragma once

namespace engine {

template <class T>
class Singleton {
	friend T;

public:
	static T& GetInstance() {
		static T instance;
		return instance;
	}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

protected:
	Singleton() = default;
	virtual ~Singleton() = default;

};

} // namespace engine
