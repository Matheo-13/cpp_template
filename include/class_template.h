#ifndef CLASS_TEMPLATE_H
#define CLASS_TEMPLATE_H

class ClassTemplate {
public:  // This is a public access specifier, which means that the members below it are accessible from outside the class.
    ClassTemplate();
    ~ClassTemplate();
    void printHello();
    void setData(int data);
    int getData() const;
    int data_public;

private: // This is a private access specifier, which means that the members below it are not accessible from outside the class.
    int m_data;

protected:  // This is a protected access specifier, which means that the members below it are accessible from derived classes.
    int data_protected;

};

class DerivedClass : public ClassTemplate { // This is an example of inheritance. DerivedClass is derived from ClassTemplate.
public:
    DerivedClass();
    ~DerivedClass();
    void printHello();
    int data_public;
    void mofidyProtectedData(int data);
    int GetProtectedData();
};


#endif // CLASS_TEMPLATE_H