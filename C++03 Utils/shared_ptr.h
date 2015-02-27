#pragma once

#include <stdexcept>

#include "detail/reference_counter.h"
#include "Preprocessor/comma_if.h"
#include "Preprocessor/generate_namelist.h"
#include "Preprocessor/generate_paramlist.h"
#include "Preprocessor/repeat.h"

namespace school {
	template<typename TPointee, typename TReferenceCounter = detail::ReferenceCounter>
	//A simple reference-counted, shared ownership smart pointer.
	struct SharedPtr {
		//Constructs a null pointer.
		SharedPtr() : ptr_(), refCounter_(new TReferenceCounter()) {
			//increment so that destructor will work properly when decrementing
			refCounter_->increment();
		}

		//Takes ownership of the given pointer.
		template<typename TCompatiblePointee>
		SharedPtr(TCompatiblePointee *unownedPtr) : ptr_(unownedPtr), refCounter_(new TReferenceCounter()) {
			refCounter_->increment();
		}

		SharedPtr(const SharedPtr &other) : ptr_(other.ptr_), refCounter_(other.refCounter_) {
			refCounter_->increment();
		}

		//Copies another SharedPtr by copying the underlying pointer and increasing the reference count.
		template<typename TCompatiblePointee>
		SharedPtr(const SharedPtr<TCompatiblePointee> &other) : ptr_(other.ptr_), refCounter_(other.refCounter_) {
			refCounter_->increment();
		}

		//Destroys the pointed-to object if it is not being referred to by any other known SharedPtr.
		~SharedPtr() {
			if (refCounter_->decrement() == 0) {
				delete refCounter_;
				delete ptr_;
			}
		}

		//Returns true if this is a null pointer, else false.
		//This would be an explicit bool conversion if for C++11.
		bool empty() const {
			return get() == 0;
		}

		//Returns the underlying pointer.
		TPointee *get() const {
			return ptr_;
		}

		//Returns a reference to the pointed-to object.
		//Throws std::logic_error if this is a null pointer.
		TPointee &operator*() const {
			if (empty()) {
				throw std::logic_error("Cannot dereference null shared_ptr.");
			}

			return *get();
		}

		//Calls a function on the pointed-to object.
		//Throws std::logic_error if this is a null pointer.
		TPointee *operator->() const {
			if (empty()) {
				throw std::logic_error("Cannot dereference null shared_ptr.");
			}

			return get();
		}

	private:
		TPointee *ptr_;
		TReferenceCounter *refCounter_;
	};

	#define MAKE_SHARED_TEMPLATE(index, data)                                                  \
		template<typename TPointee UW_COMMA_IF(index) UW_GENERATE_NAMELIST(index, typename T)> \
		SharedPtr<TPointee> makeShared(UW_GENERATE_PARAMLIST(index, T, arg)) {                 \
			return SharedPtr<TPointee>(new TPointee(UW_GENERATE_NAMELIST(index, arg)));        \
		}

	UW_REPEAT(16, MAKE_SHARED_TEMPLATE, ?)

	#undef MAKE_SHARED_TEMPLATE
}
