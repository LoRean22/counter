#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

enum class Commands {
	exit = 'x',
	increase = '+',
	decrease = '-',
	meaning = '='
};

class Counter {
private:
	int number_ = 1;

public:
	Counter(int number) : number_(number)
	{

	}

	void increment() 
	{
		number += 1;
	}

	void decrement() 
	{
		number -= 1;
	}

	int presentValue() 
	{
		return number;
	}
};

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int number;
	string answer;
	bool answerBool;
	char symbol = 's';
	Commands comm;

	cout << "\n\tВы хотите указать начальное значение счетчика? Введите 'да' или 'нет': ";
	cin >> answer;

	while (true) 
	{
		if (answer == "да") 
		{
			cout << "\tВведите начальное значение счетчика: ";
			cin >> number;
			answerBool = true;
			break;
		}
		else if (answer == "нет") 
		{
			cout << "\tНачальное значение счетчика будет выставленно по умолчанию\nЗначение счетчика = 1" << endl;
			number = 1;
			answerBool = false;
			break;
		}
		else 
		{
			cout << "\t- Введите либо 'да', либо 'нет': ";
			cin >> answer;
		}
	}

	Counter count = answerBool ? Counter(number) : Counter();

	while (true) 
	{
		cout << "\tВведите команду ('+', '-', '=' или 'x'): ";
		cin >> symbol;

		Commands comm = static_cast<Commands>(symbol);

		if (comm == Commands::exit) 
			break;


		switch (comm) 
		{
		case Commands::increase:
			count.increment();
			break;

		case Commands::decrease:
			count.decrement();
			break;

		case Commands::meaning:
			cout << "\t- " << count.presentValue() << endl;
			break;

		default:
			cout << "\t- Такой команды не существует" << endl;
			break;
		}
	}

	cout << count.presentValue() << endl;

	cout << "\t- До свидания!" << endl;

	return 0;
}