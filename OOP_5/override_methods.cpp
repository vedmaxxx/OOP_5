#include <iostream>

//В программе:
//	перекрываемые и наследуемые методы

class Source {
public:
    virtual void print() { 
        printf("Base print\n");
    }
};

class Deriv1 : public Source{};

class Deriv2 : public Source {
public:
    void print() { 
        printf("Deriv2 print\n");
    }
};

class Deriv3 : public Source {
public:
    void print() override { 
        printf("Deriv3 print - override\n");
    }
};


void override_methods()
{
    Source t;
    t.print();

    //Deriv1 просто унаследует метод print() у класса-родителя Base
    Deriv1 d1;
    d1.print();

    //Deriv2 реализует по-своему метод print(
    Deriv2 d2;
    d2.print();

    //вызовется реализация print() у класса Deriv3, поскольку присутствует override
    Deriv3 d3;
    d3.print();
}
