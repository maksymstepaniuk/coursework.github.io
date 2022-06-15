#include<iostream>
#include<conio.h>

using namespace std;

bool gameOver;//ц€ перем≥нна р≥вна Folse томущо ми спочатку не програли 
const int width = 30;//ширина 
const int height = 20;//висота
int x, y, appleX, appleY, score;//кординати зм≥йки.€блуко зм≥йка маЇ зб≥льшуватис€.score записуЇ рахунок гри 
//хв≥ст 
int tailX[100], tailY[100];
int nTail;//к≥льк≥сть елемент≥в у хвост≥ 

enum eDir { STOP = 0, LEFT, RIGHT, UP, DOWN };//enum перерахунок 
eDir dir;//зм≥нна


void Setup()//параметри 
{
	gameOver = false;
	dir = STOP;
	x = width / 2 ;// д≥лимо на 2 зм≥йка завжди буде на середин≥ 
	y = height / 2 ;
	appleX = rand() % width;
	appleY = rand() % height;
	score = 0;
}

void Draw()//малюЇ карту 
{
	system("cls");//буде очищати терм≥нал
	for (size_t i = 0; i < width + 1; i++)//буде очищати терм≥нал
	{
		cout << "#";//верхн€ границ€ 
	}
	cout << endl;

		for (size_t i = 0; i < height; i++)//висота
		{
			for (size_t j = 0; j < width; j++)
			{
				if (j == 0 || j == width - 1)//м≥нус один щоб стартувало з нул€ 
					cout << "#";
				if (i == y && j == x)
					cout << "^";
				else if (i == appleY && j == appleX)
					cout << "@";
				else {
					bool print = false;
					for (size_t h = 0; h <nTail ; h++)
					{
						if (tailX[h] == j && tailY[h] == i)
						{
							print = true;
							cout << "*";

						}
					}
					if(!print)
					cout << " ";
				}
				
			}
			cout << endl;
		}
		for (size_t i = 0; i < width + 1; i++)//нижн€ границ€
			cout <<"#";
			cout << endl;

		cout << "SCORE: " << score << endl;
}

void Input()
{
	if (_kbhit())//повертаЇ true прилюб≥й нажат≥ кнопц≥ 
	{
		switch (_getch())//в≥дсл≥дковуЇ €ку кнопку нажав користувач 
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic()//будемо перев≥р€ти 
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (size_t i = 1; i < nTail; i++)//починаЇмо з 1 тому що tailX-Y вже Ї значенн€ 0 
	{
		prev2X = tailX[0];
		prev2Y = tailY[0];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;//задаЇмо рух
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	//€кщо зм≥йка виходить за меж≥ з€вл€Їтьс€ з ≥ншого боку 
	if (x >= width-1)//м≥нус 1 тому що в Draw писали плюс
		x = 0;
	else if (x < 0)
		x = width - 2;//м≥нус 2 туму що в Draw писали плюс 1
	if (y >= height)
		y = 0;
	else if (y<0)
		y = height - 1;
	//€кщо зњсть хв≥ст
	for (size_t i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;//€кщо зм≥йка попаде на будь €кий елемент хвоста гра зак≥нченна 
	}

	if (x == appleX && y == appleY)
	{
		score += 10;//виводить €блука 
		appleX = rand() % width;
		appleY = rand() % height;
		nTail++;//зб≥льшуватиме хв≥ст 
	}
}

int main()
{
	Setup();//визиваЇмо один раз
	while (!gameOver) {
		Draw();
		Input();
		Logic();
	}
}