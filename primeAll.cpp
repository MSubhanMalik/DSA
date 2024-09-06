#include <iostream>
using namespace std;

int main() {
	int lowerLimit, upperLimit ;
	cout << "Enter a and b: " << endl;
	cin >> lowerLimit >> upperLimit;
	while (lowerLimit <= upperLimit) {
		int count = 2;
		while (count < lowerLimit) { 
			if (lowerLimit % count == 0) { 
				break;
			}
			if ((count + 1) == lowerLimit) {
				cout << lowerLimit << endl;
				break;
			}
			count++;
		}

		lowerLimit++;
	}
	
	
}
