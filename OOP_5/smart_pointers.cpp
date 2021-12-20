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
		//unique_ptr �������� ���, ����� ������ �� ������� ���������
		unique_ptr<Item> item1 = make_unique<Item>();

		//item2=nullptr
		unique_ptr<Item> item2;
		std::cout << "item1 is " << (static_cast<bool>(item1) ? "not null\n" : "null\n");
		std::cout << "item2 is " << (static_cast<bool>(item2) ? "not null\n" : "null\n");

		//item1 ������������ � nullptr
		item2 = move(item1);
		std::cout << "item1 is " << (static_cast<bool>(item1) ? "not null\n" : "null\n");
		std::cout << "item2 is " << (static_cast<bool>(item2) ? "not null\n" : "null\n");
		//��� ������ �� ������� ��������� ����� ��������� ��� ���� ���������
	}
	{
		//Item* item = new Item;

		//������� ������ Item � �������� ��� � ptr
		shared_ptr<Item> ptr = make_shared<Item>();
		printf("shared pointer ptr %p\n", &ptr);
		//���� ������� ptr1(item), �� ����� ��������� �� ����� ����� ���� � ����� 
		//� ��� ������ �� ������� ��������� ������ ��������� item, ������� ����� 
		//������� ������ ���������
		shared_ptr<Item> ptr1 = ptr;
		printf("shared pointer ptr1 %p\n", &ptr1);
	}
	{
		// �������� Item � �������� ��� � std::shared_ptr
		auto ptr1 = make_shared<Item>();
		{
			auto ptr2 = ptr1; // ������� ptr2 �� ptr1, ��������� ��������� �����������

			printf("Killing one shared pointer : %p\n", &ptr2);
		} // ptr2 ������� �� ������� ��������� �����, �� ������ ������ �� ����������
		printf("Killing another shared pointer : %p\n", &ptr1);
	}
}