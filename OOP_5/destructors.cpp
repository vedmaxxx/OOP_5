#include <iostream>

//� ���������:
//	����������� �����������

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
	printf("NotVirtBase - ������������ ����� ��� ����. �����������\n");
	printf("NotVirtArr - �������� �����, � �������� � ����������� ��������� ����������� ���������� ������\n");
	{
		NotVirtArr* arr = new NotVirtArr(10);	
		NotVirtBase* base = new NotVirtArr(30);			
		printf("���������� ���������� NotVirtArr* arr: \n");
		delete arr;

		//���������� ���������� ������������� ������, ������� �� ����� ������� ������,
		//���������� � ������������ NotVirtArr()
		printf("���������� ���������� NotVirtBase* base: \n");	
		delete base;
	}

	printf("\nVirtBase - ������������ ����� � ����. ������������\n");
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
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}