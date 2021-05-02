#pragma once

namespace clip {

	class Lock::impl {
	private:
		bool m_locked;

	public:
		impl(void* native_window_handle);
		~impl();

		bool locked() const { return m_locked; }
		bool clear();
		bool is_convertible(size_t f) const;
		bool set_data(size_t f, const char* buf, size_t len);
		bool get_data(size_t f, char* buf, size_t len) const;
		size_t get_data_length(size_t f) const;
	};

} // namespace clip