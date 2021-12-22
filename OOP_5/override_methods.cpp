#include <iostream>

//В программе:
//	перекрываемые и наследуемые методы

class Source {
public:
    virtual void print() { 
        printf("Source print\n\n");
    }
};

class Deriv1 : public Source{};

class Deriv2 : public Source {
public:
    void print() { 
        printf("Deriv2 print\n\n");
    }
};

class Deriv3 : public Source {
public:
    void print() override { 
        printf("Deriv3 print - override\n\n");
    }
};


void override_methods()
{
    printf("override_methods.cpp\n");
    printf("________________________________________________________________________________________________\n");
    printf("Создаем объект Source t\n");
    Source src;
    printf("вызываем t.print()\n");
    src.print();


    //Deriv1 просто унаследует метод print() у класса-родителя Base
    printf("Создаем объект Deriv1 d1\n");
    Deriv1 d1;
    printf("вызываем d1.print()\n");
    d1.print();

    //Deriv2 реализует по-своему метод print()
    printf("Создаем объект Deriv2 d2\n");
    Deriv2 d2;
    printf("вызываем d2.print()\n");
    d2.print();

    //вызовется реализация print() у класса Deriv3, поскольку присутствует override
    printf("Создаем объект Deriv3 d3\n");
    Deriv3 d3;
    printf("вызываем d3.print()\n");
    d3.print();
    printf("________________________________________________________________________________________________\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");


}
