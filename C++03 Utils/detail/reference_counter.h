#pragma once

namespace school {
	namespace detail {
		struct ReferenceCounter {
			ReferenceCounter() : count_() {}

			int count() const {
				return count_;
			}

			int increment() {
				return ++count_;
			}

			int decrement() {
				return --count_;
			}

		private:
			int count_;
		};
	}
}
