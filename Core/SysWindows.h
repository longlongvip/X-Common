#pragma once

#include <vector>
#include <string>

#ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#    include <Windows.h>
#endif

#include <process.h>    // for getpid,exec
#include <direct.h>     // for mkdir,rmdir,chdir,getcwd
#include <io.h>         // for open,close,read,write,lseek,tell


#include "NonCopyable.h"

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

bool run_command(const std::wstring &cmd)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    if(!CreateProcess(NULL,  //无模块名称（使用命令行）
                      const_cast<LPWSTR>(cmd.c_str()),  // 命令行
                      NULL,  // 进程不可继承
                      NULL,  // 线程不可继承
                      FALSE, // 句柄不可继承
                      0,     // 控制优先级类和进程的创建的标志
                      NULL,  // 使用父级的环境块
                      NULL,  // 使用父级的启动目录
                      &si,   // 指向STARTUPINFO结构的指针
                      &pi    // 指向PROCESS_INFORMATION结构的指针
                      ))
    {
        return false;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

class EnvVar : NonCopyable
{
public:
    static bool getEnv(const std::string& key, std::string& value, bool is_sys = true);
    static bool setEnv(const std::string& key, const std::string& value, bool is_sys = true);
    static bool remEnv(const std::string& key, bool is_sys);
};

bool EnvVar::getEnv(const std::string &key, std::string &value, bool is_sys)
{

}

bool EnvVar::setEnv(const std::string &key, const std::string &value, bool is_sys)
{

}

bool EnvVar::remEnv(const std::string &key, bool is_sys)
{
    
}


























