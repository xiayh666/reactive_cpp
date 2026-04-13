#pragma once
#include <iostream>

#include <memory>


template<typename T>
class Resource 
{
    public:
        Resource()
        {
            pdata_ = nullptr;
        }
        Resource(T data) : pdata_(std::make_unique<T>(data)) {}
        Resource(const Resource&) = delete;
        Resource& operator=(const Resource&) = delete;

    void set_value(T new_data)
    {
        if (!pdata_)
        {
            pdata_ = std::make_unique<T>(new_data);
            return;
        }
        *pdata_ = new_data;
    }

    T& get_value()
    {
        return *pdata_;
    }
    private:
        std::unique_ptr<T> pdata_;

};
