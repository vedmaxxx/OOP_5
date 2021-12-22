#include <iostream> 
using namespace std;
//В программе:
//	безопасное приведение типов(dynamic_cast)
//	безопасное приведение типов(dynamic_cast)


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
	//оператор new возвращает адрес на созданную ячейку памяти
	//создается указатель, создается объект в памяти и возвращается его адрес
	//этот адрес записывается в указатель

	//в данном случае указатель родительского класса хранит в себе адрес на объект дочернего класса
	//и не может обратиться к методам дочернего класса, поскольку они объявлены ТОЛЬКО в дочернем классе
	//и не наследуются.

	//опасное приведение типов(c-style)
	{
		printf("Опасное приведение типов(c-style)\n");
		//не можем вызвать метод getCode()
		Parent* ptr = new Child(10, 'B');

		//если ptr привести к типу Child*, тогда мы сможем вызвать getCode()
		Child* ptr1 = (Child*)ptr;
		printf("Символ: %c\n", ptr1->getCode());
		delete ptr;
	}
	//безопасное приведение типов(dynamic_cast)
	{
		printf("Безопасное приведение типов(dynamic_cast)\n");
		Parent* ptr = new Child(10, 'B');
		Child* ptr1 = dynamic_cast<Child*> (ptr);

		char symbol = '&';
		//dynamic_cast может вернуть nullptr в случае невозможной конвертации,
		//поэтому важно обрабатывать nullptr отдельно
		if (ptr1 != nullptr) {
			symbol = ptr1->getCode();
		}
		printf("Символ: %c\n", symbol);

		delete ptr;
	}
	printf("________________________________________________________________________________________________\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
