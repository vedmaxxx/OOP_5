#include <iostream>
using namespace std;

class Base {
public:
	Base() {
		printf("\t\tBase() %p\n", this);
	}
	Base(Base *obj) {
		printf("\t\tBase(Base *obj) %p\n", this);
	}
	Base(Base &obj) {
		printf("\t\tBase(Base &obj) %p\n", this);
	}

	~Base() {
		printf("\t\t~Base() %p\n", this);
	}
};

class Desc : public Base {
public:
	Desc() {
		printf("\t\tDesc() %p\n", this);
	}
	Desc(Desc* obj) {
		printf("\t\tDesc(Desc* obj) %p\n", this);
	}
	Desc(Desc& obj) {
		printf("\t\tDesc(Desc& obj) %p\n", this);
	}

	~Desc() {
		printf("\t\t~Desc() %p\n", this);
	}
};


void func1(Base obj) {
	//� ����� ������������ obj == ���. ������� �� �� ��������
	//������ ������� ������� ����� obj-�
	printf("\t\tfunc1: obj address %p\n", &obj);
	//� ������� ����� � ����� �������
}
void func2(Base* obj) {
	//����� �������� � ���������� �� ������
	printf("\t\tfunc2: obj address %p\n", obj);
}
void func3(Base& obj) {
	//����� �� �������� ������������ ����� � ����� ������ ��� ������
	printf("\t\tfunc3: obj address %p\n", &obj);
}

Base func1() {  
	//���������� ����� ��������� obj
	Base obj;
	return obj;
}
Base* func2() {  
	//
	Base* ptr = new Base;
	return ptr;
}
Base& func3() { 
	//
	Base obj;
	return obj;
}


void funcs() {
	printf("����� �������\n");
	printf("{\n");
	{
		func1(new Base);
		func2(new Base);
		func3(*(new Base));
	}
	printf("}\n\n\n");

	printf("������ � Desc\n");
	printf("{\n");

	{
		func1(new Desc);
		func2(new Desc);
		func3(*(new Desc));
	}
	printf("}\n\n\n");

	printf("������ � func1, func2, func3\n");
	printf("{\n");
	{
		printf("func1()\n");

		Base obj;
		Base* ptr = &obj;
		printf("\t\tptr = &obj: %p\n", ptr);
		//������ ���������� �� ���� �� ������
		*ptr = func1();
		printf("\t\tptr: %p\n", ptr);

		
		printf("func2()\n");
		//������ ����� ����������, ��������� � func2
		ptr = func2();
		printf("\t\tptr: %p\n", ptr);

		printf("func3()\n");
		*ptr = func3();
		printf("\t\tptr: %p\n", ptr);
	}
	printf("}\n\n\n");
}