#pragma once
#include <memory>
#include <string>

namespace clip
{
    class Lock {
    private:
        class impl;
        std::unique_ptr<impl> p;

    public:
        // You can give your current HWND as the "native_window_handle."
        // Windows clipboard functions use this handle to open/close
        // (lock/unlock) the clipboard. From the MSDN documentation we
        // need this handler so SetClipboardData() doesn't fail after a
        // EmptyClipboard() call. Anyway it looks to work just fine if we
        // call OpenClipboard() with a null HWND.
        Lock(void* native_window_handle = nullptr);
        ~Lock();

        // Returns true if we've locked the clipboard successfully in
        // lock() constructor.
        bool locked() const;

        // Clears the clipboard content. If you don't clear the content,
        // previous clipboard content (in unknown formats) could persist
        // after the unlock.
        bool clear();

        // Returns true if the clipboard can be converted to the given
        // format.
        bool is_convertible(size_t f) const;
        bool set_data(size_t f, const char* buf, size_t len);
        bool get_data(size_t f, char* buf, size_t len) const;
        size_t get_data_length(size_t f) const;

    };

    bool set_text(const std::string& value);
    bool get_text(std::string& value);
} // namespace clip