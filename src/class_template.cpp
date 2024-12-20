#include "class_template.h"
#include <iostream>


// Base class
ClassTemplate::ClassTemplate() {
    std::cout << "ClassTemplate constructor, data" << std::endl;
}

ClassTemplate::~ClassTemplate() {
    std::cout << "ClassTemplate destructor" << std::endl;
}

void ClassTemplate::printHello() {
    std::cout << "Hello, World!" << std::endl;
}

void ClassTemplate::setData(int data) {
    m_data = data;
}

int ClassTemplate::getData() const {
    return m_data;
}

// Derived class
DerivedClass::DerivedClass()
    : ClassTemplate()
{
    std::cout << "DerivedClass constructor" << std::endl;
}

DerivedClass::~DerivedClass() {
    std::cout << "DerivedClass destructor" << std::endl;
}

void DerivedClass::printHello() {
    std::cout << "Hello, World! from DerivedClass" << std::endl;
}

void DerivedClass::mofidyProtectedData(int data) {
    data_protected = data;
}   

int DerivedClass::GetProtectedData() {
    return data_protected;
}




