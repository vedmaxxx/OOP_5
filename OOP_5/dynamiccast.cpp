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
	//�������� new ���������� ����� �� ��������� ������ ������
	//��������� ���������, ��������� ������ � ������ � ������������ ��� �����
	//���� ����� ������������ � ���������

	//� ������ ������ ��������� ������������� ������ ������ � ���� ����� �� ������ ��������� ������
	//� �� ����� ���������� � ������� ��������� ������, ��������� ��� ��������� ������ � �������� ������
	//� �� �����������.
	{
		Parent* p = new Child(10, 'B');
		delete p;
	}
	//���������� ���������� �����(dynamic_cast)
	{
		Parent* p = new Child(10, 'B');
		Child* ch = dynamic_cast<Child*> (p);

		char symbol = '&';
		//dynamic_cast ����� ������� nullptr � ������ ����������� �����������,
		//������� ����� ������������ nullptr ��������
		if (ch != nullptr) {
			symbol = ch->getCode();
		}
		printf("������: %c\n", symbol);

		delete p;
	}
	
	{
		//��������� ������ Parent, �������� ����� �� ������ ������ Child
		Parent* p = new Child(200, 'A');
		
		//��������� ������ Child, �������� ����� �� ������ ������ Child, ���������� ������
		//��������� ������ Parent, ������������ � ���� ��������� ������ Child
		Child* ch = new Child((Child*)p);
		ch->getCode();
		
	}
}
