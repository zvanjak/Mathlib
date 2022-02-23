#include <iostream>
#include "calc.h"

int main(int, char**) {
    double a = 5;
    double b = 4;
    Calculator *c = new Calculator();

    std::cout << "Hello, world! 5 + 4 = " << c->Add(a, b) << std::endl;

    delete c;
}