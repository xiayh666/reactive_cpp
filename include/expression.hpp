#pragma once


#include "resource.hpp"
#include <functional>
#include <tuple>
#include <type_traits>
#include <utility>



template<typename FuncType, typename... Args>
class Expression : public Resource<std::invoke_result_t<FuncType,Args...>>
{
    using ReturnType = std::invoke_result_t<FuncType, Args...>;

    public:
        template<typename F, typename... A> 
        Expression(F&& func, A&&... args) : func_(std::forward<F>(func)), args_(std::forward<A>(args)...){}

        auto evaluate() -> ReturnType
        {
            // auto result = [&]<std::size_t... I>(std::index_sequence<I...>){
            //     return std::invoke(func_, std::get<I>(args_)...);
            // }(std::make_index_sequence<std::tuple_size_v<std::decay_t<decltype(args_)>>>{}); 
            auto result = std::apply(func_, args_);

            this->set_value(result); 
            return result;
        }
    
    private:
        std::function<ReturnType(Args...)> func_;
        std::tuple<Args...> args_;


};

template<typename F, typename... A>
Expression(F&&, A&&...) -> Expression<std::decay_t<F>, std::decay_t<A>...>;
