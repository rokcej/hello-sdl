#pragma once

#include <engine/debug.h>
#include <map>
#include <functional>
#include <utility>

namespace engine {

struct DelegateId {
	const uint32_t instance_id;
	const uint32_t callback_id;
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
		callbacks_.emplace(id.callback_id, std::move(callback));
		return id;
	}

	void operator-=(const DelegateId& id) {
		if (id.instance_id != instance_id_) {
			DEBUG_ASSERT(false, "Invalid delegate instance id");
			return;
		}
		const size_t erased_count = callbacks_.erase(id.callback_id);
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
