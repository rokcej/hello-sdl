#pragma once

#include <engine/debug.h>
#include <map>
#include <functional>
#include <utility>

namespace engine {

class DelegateId {
public:
	DelegateId() = default;
	DelegateId(uint32_t instance_id, uint32_t callback_id_);

	uint32_t GetInstanceId() const;
	uint32_t GetCallbackId() const;

private:
	uint32_t instance_id_ = 0;
	uint32_t callback_id_ = 0;

};

class DelegateBase {
protected:
	DelegateBase();
	DelegateId CreateId();

protected:
	uint32_t instance_id_ = 0;
	uint32_t callback_count_ = 0;

};

template <typename... Ts>
class Delegate : public DelegateBase {
public:
	DelegateId operator+=(std::function<void(Ts...)>&& callback) {
		const DelegateId id = CreateId();
		callbacks_.emplace(id.GetCallbackId(), std::move(callback));
		return id;
	}

	void operator-=(const DelegateId& id) {
		if (id.GetInstanceId() != instance_id_) {
			DEBUG_ASSERT(false, "Invalid delegate instance id");
			return;
		}
		const size_t erased_count = callbacks_.erase(id.GetCallbackId());
		DEBUG_ASSERT(erased_count == 1, "Invalid delegate callback id");
	}

	void operator()(Ts... parameters) {
		for (const auto& [callback_id, callback] : callbacks_) {
			callback(parameters...);
		}
	}

private:
	std::map<uint32_t, std::function<void(Ts...)>> callbacks_;

};

} // namespace engine
