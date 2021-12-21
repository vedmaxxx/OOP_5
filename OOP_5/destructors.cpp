#include <iostream>

//В программе:
//	виртуальные деструкторы

class NotVirtBase {
public:
	~NotVirtBase() {
		printf("~NotVirtBase()\n");
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
		printf("~NotVirtArr\n");
		delete[] array;
	}
};

class VirtBase {
public:
	virtual ~VirtBase() {
		printf("~VirtBase()\n");
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
		printf("~VirtArr\n");
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
		NotVirtArr* arr = new NotVirtArr(10);	//создали массив на десять чисел
		NotVirtBase* parent = arr;		//Указатель parent хранит адрес объекта, лежащего по адресу указателя arr
		delete parent;				//поскольку деструктор parent не виртуальный, вызовется ~NotVirtBase()
									//а массив останется висеть в памяти - утечка памяти
	}

	printf("VirtBase - родительский класс с вирт. деструктором\n");
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
}