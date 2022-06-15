#include<iostream>
#include<conio.h>

using namespace std;

bool gameOver;//�� �������� ���� Folse ������ �� �������� �� �������� 
const int width = 30;//������ 
const int height = 20;//������
int x, y, appleX, appleY, score;//��������� �����.������ ����� �� ������������.score ������ ������� ��� 
//���� 
int tailX[100], tailY[100];
int nTail;//������� �������� � ����� 

enum eDir { STOP = 0, LEFT, RIGHT, UP, DOWN };//enum ����������� 
eDir dir;//�����


void Setup()//��������� 
{
	gameOver = false;
	dir = STOP;
	x = width / 2 ;// ����� �� 2 ����� ������ ���� �� ������� 
	y = height / 2 ;
	appleX = rand() % width;
	appleY = rand() % height;
	score = 0;
}

void Draw()//����� ����� 
{
	system("cls");//���� ������� �������
	for (size_t i = 0; i < width + 1; i++)//���� ������� �������
	{
		cout << "#";//������ ������� 
	}
	cout << endl;

		for (size_t i = 0; i < height; i++)//������
		{
			for (size_t j = 0; j < width; j++)
			{
				if (j == 0 || j == width - 1)//���� ���� ��� ���������� � ���� 
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
		for (size_t i = 0; i < width + 1; i++)//����� �������
			cout <<"#";
			cout << endl;

		cout << "SCORE: " << score << endl;
}

void Input()
{
	if (_kbhit())//������� true ������� ����� ������ 
	{
		switch (_getch())//��������� ��� ������ ����� ���������� 
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

void Logic()//������ ��������� 
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (size_t i = 1; i < nTail; i++)//�������� � 1 ���� �� tailX-Y ��� � �������� 0 
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
		x--;//������ ���
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
	//���� ����� �������� �� ��� ���������� � ������ ���� 
	if (x >= width-1)//���� 1 ���� �� � Draw ������ ����
		x = 0;
	else if (x < 0)
		x = width - 2;//���� 2 ���� �� � Draw ������ ���� 1
	if (y >= height)
		y = 0;
	else if (y<0)
		y = height - 1;
	//���� ���� ����
	for (size_t i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;//���� ����� ������ �� ���� ���� ������� ������ ��� ��������� 
	}

	if (x == appleX && y == appleY)
	{
		score += 10;//�������� ������ 
		appleX = rand() % width;
		appleY = rand() % height;
		nTail++;//������������ ���� 
	}
}

int main()
{
	Setup();//�������� ���� ���
	while (!gameOver) {
		Draw();
		Input();
		Logic();
	}
}