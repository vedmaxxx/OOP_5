#include <iostream>

//� ���������:
//	������������� � ����������� ������

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
    printf("������� ������ Source t\n");
    Source src;
    printf("�������� t.print()\n");
    src.print();


    //Deriv1 ������ ���������� ����� print() � ������-�������� Base
    printf("������� ������ Deriv1 d1\n");
    Deriv1 d1;
    printf("�������� d1.print()\n");
    d1.print();

    //Deriv2 ��������� ��-������ ����� print()
    printf("������� ������ Deriv2 d2\n");
    Deriv2 d2;
    printf("�������� d2.print()\n");
    d2.print();

    //��������� ���������� print() � ������ Deriv3, ��������� ������������ override
    printf("������� ������ Deriv3 d3\n");
    Deriv3 d3;
    printf("�������� d3.print()\n");
    d3.print();
    printf("________________________________________________________________________________________________\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");


}
