#include <iostream>

//� ���������:
//	������������� � ����������� ������

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

    //Deriv1 ������ ���������� ����� print() � ������-�������� Base
    Deriv1 d1;
    d1.print();

    //Deriv2 ��������� ��-������ ����� print(
    Deriv2 d2;
    d2.print();

    //��������� ���������� print() � ������ Deriv3, ��������� ������������ override
    Deriv3 d3;
    d3.print();
}
