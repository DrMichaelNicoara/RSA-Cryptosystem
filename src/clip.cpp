#include <string>
#include <vector>
#include "clip.h"
#include "clip_lock_impl.h"

namespace clip
{
    Lock::Lock(void* native_window_handle)
        : p(new impl(native_window_handle)) {
    }

    Lock::~Lock() = default;

    bool Lock::locked() const {
        return p->locked();
    }

    bool Lock::clear() {
        return p->clear();
    }

    bool Lock::is_convertible(size_t f) const {
        return p->is_convertible(f);
    }

    bool Lock::set_data(size_t f, const char* buf, size_t length) {
        return p->set_data(f, buf, length);
    }

    bool Lock::get_data(size_t f, char* buf, size_t len) const {
        return p->get_data(f, buf, len);
    }

    size_t Lock::get_data_length(size_t f) const {
        return p->get_data_length(f);
    }


    bool clear() {
        Lock l;
        if (l.locked())
            return l.clear();
        else
            return false;
    }

    bool set_text(const std::string& value) {
        Lock l;
        if (l.locked()) {
            l.clear();
            return l.set_data(1, value.c_str(), value.size());
        }
        else
            return false;
    }

    bool get_text(std::string& value) {
        Lock l;
        if (!l.locked())
            return false;

        size_t f = 1;
        if (!l.is_convertible(f))
            return false;

        size_t len = l.get_data_length(f);
        if (len > 0) {
            std::vector<char> buf(len);
            l.get_data(f, &buf[0], len);
            value = &buf[0];
            return true;
        }
        else {
            value.clear();
            return true;
        }
    }
} // namespace clip