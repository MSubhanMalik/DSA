#include <iostream>
int main() {
	int a = 10;
	// You can't do like this: int b = &a where &a = Address of a
	int* b = &a; // This is special to create pointer
	std::cout << &a;
	std::cout << b;
	return 0;
}
