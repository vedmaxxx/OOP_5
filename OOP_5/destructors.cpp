#include <iostream>

//В программе:
//	виртуальные деструкторы

class NotVirtBase {
private:
	int value = 255;
public:
	~NotVirtBase() {
		printf("\t~NotVirtBase()\n");
	}
};

class NotVirtArr : public NotVirtBase{
private:
	int* array;
public:
	NotVirtArr(int size) {
		array = new int[size];
	}
	~NotVirtArr() {
		printf("\t~NotVirtArr\n");
		delete[] array;
	}
};

class VirtBase {
public:
	virtual ~VirtBase() {
		printf("\t~VirtBase()\n");
	}
};

class VirtArr : public VirtBase {
private:
	int* array;
public:
	VirtArr(int size) {
		array = new int[size];
	}
	~VirtArr() {
		printf("\t~VirtArr\n");
		delete[] array;
	}
};

void destructors()
{
	printf("desctuctors.cpp\n");
	printf("________________________________________________________________________________________________\n");
	printf("NotVirtBase - родительский класс без вирт. деструктора\n");
	printf("NotVirtArr - дочерний класс, у которого в деструкторе удаляется динамически выделенный массив\n");
	{
		NotVirtArr* arr = new NotVirtArr(10);	
		NotVirtBase* base = new NotVirtArr(30);			
		printf("Деструктор переменной NotVirtArr* arr: \n");
		delete arr;

		//вызывается деструктор РОДИТЕЛЬСКОГО класса, который не может удалить память,
		//выделенную в конструкторе NotVirtArr()
		printf("Деструктор переменной NotVirtBase* base: \n");	
		delete base;
	}

	printf("\nVirtBase - родительский класс с вирт. деструктором\n");
	printf("VirtArr - дочерний класс, у которого в деструкторе удаляется динамически выделенный массив\n");
	{
		VirtArr* arr = new VirtArr(10); 
		VirtBase* base = arr;		//указатель VirtBase хранит адрес на объект VirtArr
		delete base;				//поскольку мы удаляем объект по адресу на класс VirtBase, вызовется
									//~VirtBase(), но поскольку он виртуальный, он будет искать самый последний
									//деструктор в иерархии наследования классов - в данном случае ~VirtArr()
									//и сначала удалятся компоненты VirtArr, затем VirtBase
	}
	printf("________________________________________________________________________________________________\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}