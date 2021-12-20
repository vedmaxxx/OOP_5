#include <iostream> 
using namespace std;
//¬ программе:
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
	//оператор new возвращает адрес на созданную €чейку пам€ти
	//создаетс€ указатель, создаетс€ объект в пам€ти и возвращаетс€ его адрес
	//этот адрес записываетс€ в указатель

	//в данном случае указатель родительского класса хранит в себе адрес на объект дочернего класса
	//и не может обратитьс€ к методам дочернего класса, поскольку они объ€влены “ќЋ№ ќ в дочернем классе
	//и не наследуютс€.
	{
		Parent* p = new Child(10, 'B');
		delete p;
	}
	//безопасное приведение типов(dynamic_cast)
	{
		Parent* p = new Child(10, 'B');
		Child* ch = dynamic_cast<Child*> (p);

		char symbol = '&';
		//dynamic_cast может вернуть nullptr в случае невозможной конвертации,
		//поэтому важно обрабатывать nullptr отдельно
		if (ch != nullptr) {
			symbol = ch->getCode();
		}
		printf("—имвол: %c\n", symbol);

		delete p;
	}
	
	{
		//указатель класса Parent, хран€щий адрес на объект класса Child
		Parent* p = new Child(200, 'A');
		
		//указатель класса Child, хран€щий адрес на объект класса Child, копирующий данные
		//указател€ класса Parent, приведенного к типу указател€ класса Child
		Child* ch = new Child((Child*)p);
		ch->getCode();
		
	}
}
