#include <iostream>
using namespace std;


//���� ���������
class Base {
protected:
	int value = -1;
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

	void set(int _value) {
		value = _value;
	}
	int get() {
		return value;
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
	printf("\tBase func1()\n");
	Base obj;
	return obj;
}
Base* func2() {  
	//���������� ����� �� ���������� ������
	printf("\tBase* func2()\n");
	return new Base;
}
Base& func3(Base* obj) { 
	//���������� ������ �� ���������� obj-�
	//��� ���� ����� ��������� �� ���������
	printf("\tBase& func3()\n");
	return *obj;
}


void funcs() {
	printf("functions.cpp\n");
	printf("________________________________________________________________________________________________\n");
	printf("����� �������\n");
	printf("{\n");
	{
		printf("\tfunc1()\n");
		func1(new Base);

		printf("\tfunc2()\n");
		func2(new Base);

		printf("\tfunc3()\n");
		func3(*(new Base));
	}
	printf("}\n\n\n");

	printf("������ � Desc\n");
	printf("{\n");

	{
		printf("\tfunc1()\n");
		func1(new Desc);
		printf("\tfunc2()\n");
		func2(new Desc);
		printf("\tfunc3()\n");
		func3(*(new Desc));
	}
	printf("}\n\n\n");

	printf("������ � ��������� �� �������\n");
	printf("{\n");
	{
		printf("\tfunc1()\n");

		Base obj;
		obj.set(3);
		Base* ptr = &obj;
		printf("\t\tptr = &obj: %p\n", ptr);
		printf("\t\tobj value: %d\n", obj.get());
		//������ ���������� �� ���� �� ������
		*ptr = func1();
		printf("\t\tptr: %p\n", ptr);
		printf("\t\tobj value: %d\n", obj.get());

		
		printf("\tfunc2()\n");
		//������ ����� ����������, ��������� � func2
		ptr = func2();
		printf("\t\tptr: %p\n", ptr);


		printf("\tfunc3()\n");

		Base obj1;
		obj1.set(10);
		Base* ptr1 = &obj1;
		printf("\t\tptr1: %p\n", ptr1);
		printf("\t\tvalue: %d\n", ptr1->get());

		printf("\t\tptr: %p\n", ptr);
		printf("\t\tvalue: %d\n", ptr->get());
		*ptr = func3(ptr1);

		printf("\t\tptr: %p\n", ptr);
		printf("\t\tvalue: %d\n", ptr->get());

	}
	printf("}\n\n\n");
	printf("________________________________________________________________________________________________\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}