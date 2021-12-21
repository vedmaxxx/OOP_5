#include <iostream>

//� ���������:
//	����������� �����������

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
	printf("NotVirtBase - ������������ ����� ��� ����. �����������\n");
	printf("NotVirtArr - �������� �����, � �������� � ����������� ��������� ����������� ���������� ������\n");
	{
		NotVirtArr* arr = new NotVirtArr(10);	//������� ������ �� ������ �����
		NotVirtBase* parent = arr;		//��������� parent ������ ����� �������, �������� �� ������ ��������� arr
		delete parent;				//��������� ���������� parent �� �����������, ��������� ~NotVirtBase()
									//� ������ ��������� ������ � ������ - ������ ������
	}

	printf("VirtBase - ������������ ����� � ����. ������������\n");
	printf("VirtArr - �������� �����, � �������� � ����������� ��������� ����������� ���������� ������\n");
	{
		VirtArr* arr = new VirtArr(10); 
		VirtBase* base = arr;		//��������� VirtBase ������ ����� �� ������ VirtArr
		delete base;				//��������� �� ������� ������ �� ������ �� ����� VirtBase, ���������
									//~VirtBase(), �� ��������� �� �����������, �� ����� ������ ����� ���������
									//���������� � �������� ������������ ������� - � ������ ������ ~VirtArr()
									//� ������� �������� ���������� VirtArr, ����� VirtBase
	}
	printf("________________________________________________________________________________________________\n");
}