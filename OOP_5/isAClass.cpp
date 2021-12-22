#include <iostream> 
#include <string>
using namespace std;

//� ���������:
//	�������� �� �������������� ���������� ������


//	������� classname() �� isA(classname):
//
//	classname() ������ ���������� ��� ������, � ��������
//		�� �������������� ������ �� ��������� ��� ������
//
//	isA(classname) ��������� �� ���� ������, �� �������
//		����� �������, ����������� ������ � ����� ������ ��� ���
//		==> isA � ���� �������� �� �������������� ������

class Source {
public:

	//������ ���������� ������
	virtual const char* classname() {
		return "Base";
	}

	//��������� �� ������� ������, ����������� �� ������ ������� ������
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
		printf("��� Deriv\n");
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
	printf("���������� ����� ����� dynamic_cast � �������� �� �����\n");
	Source* base = new Deriv;
	//�������� ��������� base � ��������� ������ Deriv*
	Deriv* der = dynamic_cast<Deriv*>(base);

	//���� ������ ������ Deriv
	if (base->isA("Deriv")) {
		//�������� �����, ������� ���� ������ � Deriv
		der->printDeriv();
	}
	else printf("��� �� Deriv, � nullptr\n");
	delete base;

	Source* base1 = new Mesh;
	//�������� �������������� ��������� �� Mesh � ��������� ������ Deriv
	Deriv* der1 = dynamic_cast<Deriv*>(base1);
	//��������� - nullptr
	//���� �� nullptr - ��������
	if (der1) {
		der1->printDeriv();
	}
	else printf("��� �� Deriv, � nullptr\n");
	delete base1;
	
	//�����: �������� ������� �� �������������� ������ �����, ����� �� �����
	//������� � ������� ��������� ������ ������ ��� �����, ������� ��������� � 
	//�������� ������

	//������� ���������� ����� � ��������������� �������� ���� � ������� isA
	printf("������� ���������� ���� � ������� isA()\n");
	{
		Source* base = new Deriv;
		if (base->isA("Deriv")) {
			Deriv* der = (Deriv*)base;
			der->printDeriv();
		}
		else printf("��� �� Deriv, � nullptr\n");
	}
	printf("________________________________________________________________________________________________\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}