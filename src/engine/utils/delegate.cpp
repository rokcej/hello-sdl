#include "delegate.h"


DelegateBase::DelegateBase() {
	static uint32_t instance_count = 0;
	instance_id_ = ++instance_count;
}

DelegateId DelegateBase::CreateId() {
	return DelegateId{ instance_id_, ++callback_count_ };
}
