#pragma once

#include <atomic>

#include "NonCopyable.h"
#include "Type.h"

template<typename T>
class AtomicInteger : public NonCopyable
{
public:
    AtomicInteger() = default;

    T Get() { return value_.load(std::memory_order_relaxed); }
    T GetInc()
    {
        return  value_.fetch_add(1, std::memory_order_relaxed);
    }

    void Inc()
    {
        value_.fetch_add(1, std::memory_order_relaxed);
    }

    void Inc(T x)
    {
        value_.fetch_add(x, std::memory_order_relaxed);
    }

    void Dec()
    {
        value_.fetch_sub(1, std::memory_order_relaxed);
    }

    void Dec(T x)
    {
        value_.fetch_sub(x, std::memory_order_relaxed);
    }

    void Set(T value)
    {
        value_.store(value);
    }

private:
    std::atomic<T> value_ = 0;
};

using AtomicInt = AtomicInteger<int>;
using AtomicInt64 = AtomicInteger<int64>;
