#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print(char arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 1) cout << " | " << arr[i][j] << " | ";
			else cout << arr[i][j];
		}
		cout << endl << "---------" << endl;
	}
}

bool checkWin(char arr[3][3], char n) {
	for (int i = 0; i < 3; i++) {
		if (arr[i][0] == n && arr[i][1] == n && arr[i][2] == n) return true;
		if (arr[0][i] == n && arr[1][i] == n && arr[2][i] == n) return true;
	}
	if (arr[0][0] == n && arr[1][1] == n && arr[2][2] == n) return true;
	if (arr[0][2] == n && arr[1][1] == n && arr[2][0] == n) return true;
}

void AIMove(char arr[3][3], char n, int &n1, int &n2) {
	bool found = false;
	while (found != true) {
		int num1 = rand() % 3;
		int num2 = rand() % 3;
		if (arr[num1][num2] == ' ')
		{
			found = true;
			n1 = num1;
			n2 = num2;

		}
	}
}
bool checkValidRange(int coordinates[]) {
	if (coordinates[0] >= 0 && coordinates[0] <= 2)
	{
		if (coordinates[1] >= 0 && coordinates[1] <= 2) return true;
		else return false;
	}
	else return false;
}

void checkGameDraw(char arr[3][3], int &over) {
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] != ' ') {
				count++;
				if (count == 9)
				{
					cout << endl << "Game Over:  Draw" << endl;
					over = 1;
					break;
				}
			}
			else continue;
		}
	}
}

int main() {

	char arr[3][3] = { {' ',' ',' '}, {' ',' ', ' '}, {' ',' ', ' '} };
	cout << "Tic-Tac-Toe Game" << endl;
	print(arr);
	int win = 0, over = 0;
	bool player = 1;
	char n;
	int mode;
	cout << "Enter the mode, 1 for Singular, 2 for 2 players: ";
	cin >> mode;
	cout << endl;
	while (over != 1) {
		int coordinates[2];
		int win = false;
		bool valid = true;
		if (player == 1) n = 'X';
		else n = 'O';
		
		switch (mode) {
		case 1:
			{
			if (n == 'X') {
				cout << "Player X, enter row and column: ";
				cin >> coordinates[0] >> coordinates[1];
			}
			else {
				int n1, n2;
				AIMove(arr, n, n1, n2);
				coordinates[0] = n1;
				coordinates[1] = n2;
				cout << endl << coordinates[0] << ", " << coordinates[1] << " " << endl;
			}
			break;
			}
		case 2:
			{
			cout << "Player " << n << ", enter row and column: ";
			cin >> coordinates[0] >> coordinates[1];
			break;
			}
		}
		
		valid = checkValidRange(coordinates);
		if (valid == false) {
			cout << endl<< "Invalid Input. Please write within range (0-2)." << endl;
			continue;
		}

		if(arr[coordinates[0]][coordinates[1]] == ' ') arr[coordinates[0]][coordinates[1]] = n;
		else {
			cout<< "Invalid Move. Please Try again" << endl;
			continue;
		}
		print(arr);
		player = !player;

		win = checkWin(arr, n);
		if (win == true) {
			cout << endl << "Player " << n << " won." << endl;
			break;
		}
		checkGameDraw(arr, over);
	}
}
