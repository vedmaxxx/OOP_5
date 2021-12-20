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
	//с самим оригинальным obj == арг. функции он не работает
	//внутри функции создает копию obj-а
	printf("func1: obj address %p\n", &obj);
	//и удаляет копию в самой функции
}
void func2(Base* obj) {
	//здесь работаем с указателем на объект
	printf("func2: obj address %p\n", obj);
}
void func3(Base& obj) {
	//здесь мы получаем оригинальный адрес и можем менять сам объект
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
	printf("начало\n");
	{
		func1(new Base);
		func2(new Base);
		func3(*(new Base));
	}
	printf("Работа с Desc\n");
	{
		func1(new Desc);
		func2(new Desc);
		func3(*(new Desc));
	}
	{
		
	}

}