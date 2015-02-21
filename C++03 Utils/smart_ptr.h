#pragma once

namespace school {
	template<typename TPointee>
	struct SmartPtr {
		SmartPtr() {
			ptr_ = 0;
		}

		TPointee *get() const {
			return ptr_;
		}

	private:
		TPointee *ptr_;
	};
}