#include <iostream>
using namespace std;

class Base {
public:
	Base() {
		printf("Base() %p\n", this);
	}
	Base(Base *obj) {
		printf("Base(Base *obj) %p\n", this);
	}
	Base(Base &obj) {
		printf("Base(Base &obj) %p\n", this);
	}

	~Base() {
		printf("~Base() %p\n", this);
	}
};

class Desc : public Base {
public:
	Desc() {
		printf("Desc() %p\n", this);
	}
	Desc(Desc* obj) {
		printf("Desc(Desc* obj) %p\n", this);
	}
	Desc(Desc& obj) {
		printf("Desc(Desc& obj) %p\n", this);
	}

	~Desc() {
		printf("~Desc() %p\n", this);
	}
};


void func1(Base obj) {
	//� ����� ������������ obj == ���. ������� �� �� ��������
	//������ ������� ������� ����� obj-�
	printf("func1: obj address %p\n", &obj);
	//� ������� ����� � ����� �������
}
void func2(Base* obj) {
	//����� �������� � ���������� �� ������
	printf("func2: obj address %p\n", obj);
}
void func3(Base& obj) {
	//����� �� �������� ������������ ����� � ����� ������ ��� ������
	printf("func3: obj address %p\n", &obj);
}

Base func1() {  
	Base obj;
	return obj;
}
Base* func2() {  
	Base* ptr;
	return ptr;
}
Base& func3() { 
	return *(new Base);
}


void funcs() {
	printf("������\n");
	{
		func1(new Base);
		func2(new Base);
		func3(*(new Base));
	}
	printf("������ � Desc\n");
	{
		func1(new Desc);
		func2(new Desc);
		func3(*(new Desc));
	}
	{
		
	}

}