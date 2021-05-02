#include "clip.h"
#include "clip_lock_impl.h"

#include <cassert>
#include <map>
#include <vector>

namespace clip {

    typedef std::vector<char> Buffer;
    typedef std::map<size_t, Buffer> Map;

    static size_t g_last_format = 100;
    static Map g_data;

    Lock::impl::impl(void* native_handle) : m_locked(true) {
    }

    Lock::impl::~impl() {
    }

    bool Lock::impl::clear() {
        g_data.clear();
        return true;
    }

    bool Lock::impl::is_convertible(size_t f) const {
        return (g_data.find(f) != g_data.end());
    }

    bool Lock::impl::set_data(size_t f, const char* buf, size_t len) {
        Buffer& dst = g_data[f];

        dst.resize(len);
        if (buf && len > 0)
            std::copy(buf, buf + len, dst.begin());

        return true;
    }

    bool Lock::impl::get_data(size_t f, char* buf, size_t len) const {
        assert(buf);

        if (!buf || !is_convertible(f))
            return false;

        const Buffer& src = g_data[f];
        std::copy(src.begin(), src.end(), buf);
        return true;
    }

    size_t Lock::impl::get_data_length(size_t f) const {
        if (is_convertible(f))
            return g_data[f].size();
        else
            return 0;
    }
} // namespace clip