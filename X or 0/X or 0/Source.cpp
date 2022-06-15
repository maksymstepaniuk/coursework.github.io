#include <iostream>
#include <ctime>
using namespace std;

#include "Header.h";

int main()
{
    srand(unsigned(time(0)));
    char cell[3][3]{};
    startGame(cell);
    print(cell);
    char check;
    for (size_t i = 0; i < 9; i++)
    {
        if (i % 2 == 0)
            player(cell, 'X');
        else
            bot(cell, '0');
        if (i >= 4) {
            check = checkWinner(cell);
            if (check != ' ') break;
        }
    }
    if (check == ' ') cout << "Draw !!! " << endl;
    else cout << check << "'s wins !!!" << endl;

    return 0;
}
