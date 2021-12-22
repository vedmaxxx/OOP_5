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
		printf("������ � unique_ptr\n");

		//unique_ptr �������� ���, ����� ������ �� ������� ���������
		unique_ptr<Item> item1 = make_unique<Item>();

		//item2 = nullptr
		unique_ptr<Item> item2;

		cout << "item1: " << (static_cast<bool>(item1) ? "�� nullptr\n" : "nullptr\n");
		cout << "item2: " << (static_cast<bool>(item2) ? "�� nullptr\n" : "nullptr\n");

		//item1 ������������ � nullptr
		item2 = move(item1);
		cout << "item1: " << (static_cast<bool>(item1) ? "�� nullptr\n" : "nullptr\n");
		cout << "item2: " << (static_cast<bool>(item2) ? "�� nullptr\n" : "nullptr\n");
		//��� ������ �� ������� ��������� ����� ��������� ��� ���� ���������
	}
	printf("\n");
	{
		printf("������ � shared_ptr\n");

		//������� ������ Item � �������� ��� � ptr
		shared_ptr<Item> ptr0 = make_shared<Item>();
		printf("shared_ptr ptr0 %p\n", &ptr0);
		//���� ������� ptr1(item), �� ����� ��������� �� ����� ����� ���� � ����� 
		//� ��� ������ �� ������� ��������� ������ ��������� item, ������� ����� 
		//������� ������ ���������
		shared_ptr<Item> ptr1 = ptr0;
		printf("shared_ptr ptr1 %p\n", &ptr1);
	}
	printf("\n");

	{
		printf("������ � auto_ptr(shared_ptr)\n");
		auto ptr1 = make_shared<Item>();
		{
			auto ptr2 = ptr1; // ������� ptr2 �� ptr1, ��������� ��������� �����������
			printf("������������ ��������� ptr2 : %p\n", &ptr2);
		} // ptr2 ������� �� ������� ��������� �����, �� ������ ������ �� ����������
		printf("������������ ��������� ptr1 : %p\n", &ptr1);
	}
	printf("________________________________________________________________________________________________\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}