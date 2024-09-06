#include <iostream>
using namespace std;

int main() {
	int num1, num2;
	char operation;
	cout << "Input an operation: ";
	cin >> operation;
	cout << endl << "Enter number 1: ";
	cin >> num1;
	cout << endl << "Enter number 2: ";
	cin >> num2;
// Same can be done with if else
	switch (operation) {
	case '+':
		cout << num1 + num2 << endl;
		break;
	case '-':
		cout << num1 - num2 << endl;
		break;
	case '*':
		cout << num1 * num2 << endl;
		break;
	case '/':
		cout << num1 / num2 << endl;
		break;
	case '%':
		cout << num1 % num2 << endl;
		break;
	default:
		cout << "Sorry but no operation like this." << endl;
			
	}
	return 0;
}
