#include <iostream>
#include "hello.h"
#include "class_template.h"

int main() {
    printHello();
    ClassTemplate ct;
    DerivedClass dc;
    ct.printHello();
    dc.printHello();
    ct.data_public = 42;
    dc.data_public = 66;
    std::cout << "Data Public: " << ct.data_public << std::endl;
    std::cout << "Data Public: " << dc.data_public << std::endl;
    ct.setData(100);
    dc.setData(200);
    std::cout << "Data Private: " << ct.getData() << std::endl;
    std::cout << "Data Private: " << dc.getData() << std::endl;
    dc.mofidyProtectedData(300);
    std::cout << "Protected Data: " << dc.GetProtectedData() << std::endl;
    return 0;
}