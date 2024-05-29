#pragma once

#include <memory>

template<typename T, typename ...Arg>
std::unique_ptr<T> make_unique(Arg&& ...args)
{
    return std::unique_ptr<T>(new T(std::forward<Arg>(args)...));
}

#define x_is_integral(x) std::is_integral<x>::value

#define x_for(x, v) for(x : v)
