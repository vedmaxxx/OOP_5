#include <iostream>
using namespace std;

class Item {
public:
	Item() { 
		printf("Item()\n"); 
	}
	void someMethod(){}

	~Item() { 
		printf("~Item()\n"); 
	}
};

void pointers() {
	{
		printf("smart_pointers.cpp\n");
		printf("________________________________________________________________________________________________\n");
		printf("Работа с unique_ptr\n");

		//unique_ptr удалится сам, когда выйдет из области видимости
		unique_ptr<Item> item1 = make_unique<Item>();

		//item2 = nullptr
		unique_ptr<Item> item2;

		cout << "item1: " << (static_cast<bool>(item1) ? "не nullptr\n" : "nullptr\n");
		cout << "item2: " << (static_cast<bool>(item2) ? "не nullptr\n" : "nullptr\n");

		//item1 превращается в nullptr
		item2 = move(item1);
		cout << "item1: " << (static_cast<bool>(item1) ? "не nullptr\n" : "nullptr\n");
		cout << "item2: " << (static_cast<bool>(item2) ? "не nullptr\n" : "nullptr\n");
		//при выходе из области видимости умный указатель сам себя уничтожит
	}
	printf("\n");
	{
		printf("Работа с shared_ptr\n");

		//создает объект Item и передает его в ptr
		shared_ptr<Item> ptr0 = make_shared<Item>();
		printf("shared_ptr ptr0 %p\n", &ptr0);
		//если сделаем ptr1(item), то умные указатели не будут знать друг о друге 
		//и при выходе из области видимости просто уничтожат item, которым может 
		//владеть второй указатель
		shared_ptr<Item> ptr1 = ptr0;
		printf("shared_ptr ptr1 %p\n", &ptr1);
	}
	printf("\n");

	{
		printf("Работа с auto_ptr(shared_ptr)\n");
		auto ptr1 = make_shared<Item>();
		{
			auto ptr2 = ptr1; // создаем ptr2 из ptr1, используя семантику копирования
			printf("уничтожается указатель ptr2 : %p\n", &ptr2);
		} // ptr2 выходит из области видимости здесь, но ничего больше не происходит
		printf("уничтожается указатель ptr1 : %p\n", &ptr1);
	}
	printf("________________________________________________________________________________________________\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}