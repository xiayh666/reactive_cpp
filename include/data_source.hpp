#pragma once
#include "expression.hpp"
#include "resource.hpp"
#include <utility>

namespace reactive
{

template<typename T>
auto var(T val) -> Resource<T>
{
    return Resource(val);
}

template<typename F, typename... A>
auto calc(F func, A... args) -> Expression<F, A...>
{
    return Expression(std::forward<F>(func), std::forward<A>(args)...);
}






};
