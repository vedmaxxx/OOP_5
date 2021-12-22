#include <iostream> 
#include <string>
using namespace std;

//В программе:
//	проверка на принадлежность некоторому классу


//	отличие classname() от isA(classname):
//
//	classname() просто возвращает имя класса, и проверку
//		на принадлежность классу мы реализуем ВНЕ класса
//
//	isA(classname) принимает на вход строку, по которой
//		можно сказать, принадлежит объект к этому классу или нет
//		==> isA и есть проверка на принадлежность классу

class Source {
public:

	//просто возвращает строку
	virtual const char* classname() {
		return "Base";
	}

	//проверяет по входной строке, принадлежит ли объект данному классу
	virtual bool isA(const char* classname) {
		if (classname == "Base") return true;
		else return false;
	}
};

class Deriv : public Source {
public:

	virtual const char* classname() override { 
		return "Deriv";
	}

	virtual bool isA(const char* classname) override {
		if (classname == "Deriv") return true;
		else return false;
	}

	void printDeriv() {
		printf("это Deriv\n");
	}
};

class Mesh : public Source {
public:

	virtual const char* classname() override {
		return "Mesh";
	}

	virtual bool isA(const char* classname) override {
		if (classname == "Mesh") return true;
		else return false;
	}
};

void isAClass()
{
	printf("isAClass.cpp\n");
	printf("________________________________________________________________________________________________\n");
	printf("Приведение типов через dynamic_cast и проверка на класс\n");
	Source* base = new Deriv;
	//приводим указатель base к дочернему классу Deriv*
	Deriv* der = dynamic_cast<Deriv*>(base);

	//если объект класса Deriv
	if (base->isA("Deriv")) {
		//вызываем метод, который есть только у Deriv
		der->printDeriv();
	}
	else printf("Это не Deriv, а nullptr\n");
	delete base;

	Source* base1 = new Mesh;
	//пытается конвертировать указатель на Mesh в указатель класса Deriv
	Deriv* der1 = dynamic_cast<Deriv*>(base1);
	//результат - nullptr
	//если не nullptr - печатаем
	if (der1) {
		der1->printDeriv();
	}
	else printf("Это не Deriv, а nullptr\n");
	delete base1;
	
	//вывод: проверка объекта на принадлежность классу нужна, чтобы мы могли
	//вызвать у объекта дочернего класса именно тот метод, который определен в 
	//дочернем классе

	//опасное приведение типов и предварительная проверка типа с помощью isA
	printf("Опасное приведение типа с помощью isA()\n");
	{
		Source* base = new Deriv;
		if (base->isA("Deriv")) {
			Deriv* der = (Deriv*)base;
			der->printDeriv();
		}
		else printf("Это не Deriv, а nullptr\n");
	}
	printf("________________________________________________________________________________________________\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}