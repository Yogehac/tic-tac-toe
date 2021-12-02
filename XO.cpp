#include <iostream>
using namespace std;

int linearSearch(char *arr)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == '-')
            return i;
    }
    return -1;
}

bool checkGame(char *arr, int input)
{
    if (linearSearch(arr) > 0)
    {
        switch (input)
        {
        case 0:
            if ((arr[0] == arr[1]) && (arr[1] == arr[2]))
                return true;
            else if ((arr[0] == arr[4]) && (arr[4] == arr[8]))
                return true;
            else if ((arr[0] == arr[3]) && (arr[3] == arr[6]))
                return true;
            else
                return false;
        case 1:
            if ((arr[0] == arr[1]) && (arr[1] == arr[2]))
                return true;
            else if ((arr[1] == arr[4]) && (arr[4] == arr[7]))
                return true;
            else
                return false;
        case 2:
            if ((arr[0] == arr[2]) && (arr[2] == arr[1]))
                return true;
            else if ((arr[5] == arr[2]) && (arr[2] == arr[8]))
                return true;
            else
                return false;
        case 3:
            if ((arr[0] == arr[3]) && (arr[3] == arr[6]))
                return true;
            else if ((arr[4] == arr[3]) && (arr[3] == arr[5]))
                return true;
            else
                return false;
        case 4:
            if ((arr[4] == arr[0]) && (arr[0] == arr[8]))
                return true;
            else if ((arr[4] == arr[3]) && (arr[3] == arr[5]))
                return true;
            else if ((arr[4] == arr[1]) && (arr[1] == arr[7]))
                return true;
            else if ((arr[4] == arr[6]) && (arr[6] == arr[2]))
                return true;
            else
                return false;
        case 5:
            if ((arr[5] == arr[3]) && (arr[3] == arr[4]))
                return true;
            else if ((arr[5] == arr[2]) && (arr[2] == arr[8]))
                return true;
            else
                return false;
        case 6:
            if ((arr[6] == arr[3]) && (arr[3] == arr[0]))
                return true;
            else if ((arr[6] == arr[7]) && (arr[7] == arr[8]))
                return true;
            else
                return false;
        case 7:
            if ((arr[6] == arr[7]) && (arr[7] == arr[8]))
                return true;
            else if ((arr[4] == arr[1]) && (arr[1] == arr[7]))
                return true;
            else
                return false;
        case 8:
            if ((arr[4] == arr[8]) && (arr[8] == arr[0]))
                return true;
            else if ((arr[2] == arr[8]) && (arr[8] == arr[5]))
                return true;
            else if ((arr[6] == arr[7]) && (arr[7] == arr[8]))
                return true;
            else
                return false;
        default:
            return false;
        }
    }
    else
    {
        cout << "else part";
        return true;
    }
}

void display(char *arr, int count)
{
    system("cls");
    cout << "Player 1 = X" << endl;
    cout << "Player 2 = O\n"
         << endl;
    for (int i = 0; i < 9; i++)
    {
        count++;
        cout << arr[i] << "\t";
        if (count % 3 == 0)
            cout << endl;
    }
}

void call(int *player, int play, char *arr)
{
    do
    {
        if (play == 1)
            cout << "Player 1 : ";
        else
            cout << "Player 2 : ";

        cin >> *player;
        if (arr[*player - 1] != '-')
        {
            cout << "Invalid Option!" << endl;
        }
    } while (arr[*player - 1] != '-');

    arr[(*player - 1)] = play == 1 ? 'X' : 'O';

    display(arr, 0);
}

int main()
{
    char gameArr[9];
    int player1, player2, opt;

    do
    {
        for (int i = 0; i < 9; i++)
        {
            gameArr[i] = '-';
        }
        display(gameArr, 0);

        do
        {
            call(&player1, 1, gameArr);
            if (checkGame(gameArr, player1 - 1))
                break;

            call(&player2, 2, gameArr);
            if (checkGame(gameArr, player2 - 1))
                break;

        } while (true);

        if (linearSearch(gameArr) == -1)
            cout << "Match tied" << endl;
        else
            cout << "You won!" << endl;
        cout << "Press 1 to play again   OR   Press any key to exit.\n";
        cin >> opt;
    } while (opt == 1);
    return 0;
}