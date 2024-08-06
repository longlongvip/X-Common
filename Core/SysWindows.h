#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#    include <Windows.h>
#endif

class ScopedWinHandle
{
public:
    ScopedWinHandle(HANDLE handle) : handle_(handle) { }
    ScopedWinHandle() : handle_(INVALID_HANDLE_VALUE) { }
    ~ScopedWinHandle()
    {
        set(INVALID_HANDLE_VALUE);
    }

    HANDLE get() const { return handle_; }
    void set(HANDLE handle)
    {
        if(isValid())
        {
            CloseHandle(handle_);
        }
        handle_ = handle;
    }

    HANDLE release()
    {
        HANDLE h = handle_;
        handle_ = INVALID_HANDLE_VALUE;
        return h;
    }

    bool isValid() const { return handle_ != INVALID_HANDLE_VALUE; }
    bool operator !() const { return !isValid(); }

    operator HANDLE() const { return handle_; }
    HANDLE operator ->() const { return handle_; }
    HANDLE* operator &() { return &handle_; }
    const HANDLE* operator &() const { return &handle_; }

private:
    HANDLE handle_;
};
