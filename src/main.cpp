#include <iostream>
#include <data_source.hpp>

int main(int argc, char **argv) {
    auto a = reactive::var("hello reactive");

    std::cout << a.get_value() << std::endl;

    a.set_value("after");
    std::cout << a.get_value() << std::endl;


    auto b = reactive::calc([](int a, int b){return a + b;}, 10, 25);
    b.evaluate();
    std::cout << b.get_value() << std::endl; 




    return 0;
}
