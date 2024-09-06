#include <iostream>
using namespace std;

int main() {
	int num, lastDigit, sum = 0;
	cout << "Enter any number: ";
	cin >> num;
	cout << endl;
	cout << "Number: " << num;
	while (num!=0) {
		lastDigit = num % 10; 
		num = num / 10; 
		sum += lastDigit; 
	}
	cout << " Sum : "<< sum;
	return 0;
}
