#include "delegate.h"

namespace engine {

DelegateId::DelegateId(uint32_t instance_id, uint32_t callback_id) {
	instance_id_ = instance_id;
	callback_id_ = callback_id;
}

uint32_t DelegateId::GetInstanceId() const {
	return instance_id_;
}

uint32_t DelegateId::GetCallbackId() const {
	return callback_id_;
}


DelegateBase::DelegateBase() {
	static uint32_t instance_count = 0;
	instance_id_ = ++instance_count;
}

DelegateId DelegateBase::CreateId() {
	return DelegateId(instance_id_, ++callback_count_);
}

} // namespace engine
