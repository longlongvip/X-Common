#pragma once

#include <memory>

template<typename T>
using Scope = std::unique_ptr<T>;
template<typename T, typename ...Args>
Scope<T> CreateScope(Args&& ...args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using Ref = std::shared_ptr<T>;
template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

#define x_is_integral(x) std::is_integral<x>::value

#define x_for(x, v) for(x : v)

#define X_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }


