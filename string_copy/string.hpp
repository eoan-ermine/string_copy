#include <cstring>
#include <utility>

class string {
	char *data_;
	std::size_t size_;
	std::size_t capacity_;

	void swap(string& rhs) noexcept {
		std::swap(this->data_, rhs.data_);
		std::swap(this->size_, rhs.size_);
		std::swap(this->capacity_, rhs.capacity_);
	}
public:
	string (const char* rhs) noexcept(false) {
		std::size_t size = std::strlen(rhs);
		data_ = new char[size];

		// ^ Possibly throws
		// -------------------------
		// Code below: changes invariants 

		capacity_ = size_ = size;
		std::memcpy(data_, rhs, size_);
	}

	string(const string& rhs) noexcept(false) {
		data_ = new char[rhs.size_];

		// ^ Possibly throws
		// -------------------------
		// Code below: changes invariants 

		capacity_ = size_ = rhs.size_;
		std::memcpy(data_, rhs.data_, rhs.size_);
	}

	string& operator=(const string& rhs) noexcept(false) {
		if (this == &rhs)
			return *this;
		string newString(rhs);

		// ^ Possibly throws
		// -------------------------
		// Code below: changes invariants 

		swap(newString);
		return *this;
	}

	~string() noexcept {
		delete[] data_;
	}
};