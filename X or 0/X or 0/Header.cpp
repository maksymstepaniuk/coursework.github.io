#include <iostream>
#include "Header.h"

using std::cout;
using std::cin;
using std::endl;

int length = 3;
int x, y;
void startGame(char arr[][3])
{
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void gorizont()
{
	for (size_t j = 0; j < length; j++)
	{
		cout << char(205) << char(205) << char(205) << " ";
	}
}

void print(char arr[][3])
{
	system("cls");
	cout << endl;
	int counter = 0;
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			if (j == 0) cout << " ";

			cout << arr[i][j];

			if (j < length - 1)
				cout << " " << char(186) << " ";
		}
		cout << "\t\t\t";
		for (size_t j = 0; j < length; j++)
		{
			if (j == 0) cout << " ";

			cout << ++counter;

			if (j < length - 1)
				cout << " " << char(186) << " ";
		}
		cout << endl;
		if (i == length - 1) break;
		gorizont();
		cout << "\t\t\t";
		gorizont();
		cout << endl;
		// X | X | X			 1 | 2 | 3
		//--- --- ---			--- --- ---
	}
}

void convertPosition(int position)
{
	switch (position)
	{
	case 1: x = 0; y = 0; break;
	case 2: x = 0; y = 1; break;
	case 3: x = 0; y = 2; break;
	case 4: x = 1; y = 0; break;
	case 5: x = 1; y = 1; break;
	case 6: x = 1; y = 2; break;
	case 7: x = 2; y = 0; break;
	case 8: x = 2; y = 1; break;
	case 9: x = 2; y = 2; break;
	}
}

void player(char arr[][3], char symbol)
{
	int position;
	do {
		cout << "Enter position [1 - 9] : ";
		cin >> position;
		convertPosition(position);
	} while (arr[x][y] != ' ' || position < 1 || position > 9);
	arr[x][y] = symbol;
	print(arr);
}

void bot(char arr[][3], char symbol)
{
	int position;
	do {
		position = 1 + rand() % 9;
		convertPosition(position);
	} while (arr[x][y] != ' ');
	arr[x][y] = symbol;
	print(arr);
}

char checkWinner(char arr[][3])
{

	if (arr[0][0] != ' ')
	{
		if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2]
			|| arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]
			|| arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0])
		{
			return arr[0][0];
		}
	}
	if (arr[0][1] != ' ')
	{
		if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1])
		{
			return arr[0][1];
		}
	}
	if (arr[0][2] != ' ')
	{
		if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]
			|| arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2]
			)
		{
			return arr[0][2];
		}
	}
	if (arr[1][0] != ' ')
	{
		if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2])
		{
			return arr[1][0];
		}
	}
	if (arr[2][0] != ' ')
	{
		if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2])
		{
			return arr[2][0];
		}
	}

	return ' ';
}