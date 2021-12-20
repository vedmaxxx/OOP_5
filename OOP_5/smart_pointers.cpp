#include <iostream>
using namespace std;

class Item {
public:
	Item() { printf("Item acquired\n"); }
	void someMethod(){}
	~Item() { printf("Item destroyed\n"); }
};

void pointers() {
	{
		//unique_ptr удалится сам, когда выйдет из области видимости
		unique_ptr<Item> item1 = make_unique<Item>();

		//item2=nullptr
		unique_ptr<Item> item2;
		std::cout << "item1 is " << (static_cast<bool>(item1) ? "not null\n" : "null\n");
		std::cout << "item2 is " << (static_cast<bool>(item2) ? "not null\n" : "null\n");

		//item1 превращается в nullptr
		item2 = move(item1);
		std::cout << "item1 is " << (static_cast<bool>(item1) ? "not null\n" : "null\n");
		std::cout << "item2 is " << (static_cast<bool>(item2) ? "not null\n" : "null\n");
		//при выходе из области видимости умный указатель сам себя уничтожит
	}
	{
		//Item* item = new Item;

		//создает объект Item и передает его в ptr
		shared_ptr<Item> ptr = make_shared<Item>();
		printf("shared pointer ptr %p\n", &ptr);
		//если сделаем ptr1(item), то умные указатели не будут знать друг о друге 
		//и при выходе из области видимости просто уничтожат item, которым может 
		//владеть второй указатель
		shared_ptr<Item> ptr1 = ptr;
		printf("shared pointer ptr1 %p\n", &ptr1);
	}
	{
		// Выделяем Item и передаем его в std::shared_ptr
		auto ptr1 = make_shared<Item>();
		{
			auto ptr2 = ptr1; // создаем ptr2 из ptr1, используя семантику копирования

			printf("Killing one shared pointer : %p\n", &ptr2);
		} // ptr2 выходит из области видимости здесь, но ничего больше не происходит
		printf("Killing another shared pointer : %p\n", &ptr1);
	}
}