#include <iostream> 
using namespace std;
//� ���������:
//	���������� ���������� �����(dynamic_cast)
//	���������� ���������� �����(dynamic_cast)


class Parent {
protected:
	int value;
public:
	Parent() : value(0) {}
	Parent(int _value) : value(_value) {}

	virtual ~Parent() {}
};

class Child : public Parent {
private:
	char code;
public:
	Child(int _value, char _code) : Parent(_value), code(_code) {}
	const char getCode() {
		return code;
	}
	Child(const Child* ch) {
		printf("Child(Child& ch) %p\n", this);
		this->value = ch->value;
		this->code = ch->code;
	}
};

void dynamiccast()
{
	printf("dynamiccast.cpp\n");
	printf("________________________________________________________________________________________________\n");
	//�������� new ���������� ����� �� ��������� ������ ������
	//��������� ���������, ��������� ������ � ������ � ������������ ��� �����
	//���� ����� ������������ � ���������

	//� ������ ������ ��������� ������������� ������ ������ � ���� ����� �� ������ ��������� ������
	//� �� ����� ���������� � ������� ��������� ������, ��������� ��� ��������� ������ � �������� ������
	//� �� �����������.

	//������� ���������� �����(c-style)
	{
		printf("������� ���������� �����(c-style)\n");
		//�� ����� ������� ����� getCode()
		Parent* ptr = new Child(10, 'B');

		//���� ptr �������� � ���� Child*, ����� �� ������ ������� getCode()
		Child* ptr1 = (Child*)ptr;
		printf("������: %c\n", ptr1->getCode());
		delete ptr;
	}
	//���������� ���������� �����(dynamic_cast)
	{
		printf("���������� ���������� �����(dynamic_cast)\n");
		Parent* ptr = new Child(10, 'B');
		Child* ptr1 = dynamic_cast<Child*> (ptr);

		char symbol = '&';
		//dynamic_cast ����� ������� nullptr � ������ ����������� �����������,
		//������� ����� ������������ nullptr ��������
		if (ptr1 != nullptr) {
			symbol = ptr1->getCode();
		}
		printf("������: %c\n", symbol);

		delete ptr;
	}
	printf("________________________________________________________________________________________________\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
