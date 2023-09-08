#include <iostream>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

bool ask()
{
    char c;
    cout << endl
         << " --------------------------------------------------------" << endl
         << "Again ? (1,0)" << endl;
    cin >> c;
    fflush(stdin);
    return (c == '0' ? false : true);
}

void displayBoard(char Board[3][3]);
unsigned char checkBoard(char Board[3][3], char PlayerCharacter);
bool updateBoard(char Board[3][3], pair<int, int> moveIndexes, char PlayerCharacter);

int main()
{
    do
    {
        clearScreen();

        bool flagEnd = false;
        bool flagPlayer1Turn = true;
        char PlayerCharacter = 'X';
        char Board[3][3] = {{0}};
        pair<int, int> moveIndexes;

        while (!flagEnd)
        {
            char index1, index2;
            clearScreen();
            cout << "State: ongoing" << endl
                 << endl;
            displayBoard(Board);
            cout << setw(8) << "Player" << (flagPlayer1Turn ? "1" : "2") << " turn: (" << PlayerCharacter << ")" << endl
                 << endl
                 << "Enter the indices of the cell : (1:3) (1:3) " << endl
                 << endl;
            cin >> index1 >> index2;
            fflush(stdin);
            moveIndexes = {(int)index1 - (int)'0', (int)index2 - (int)'0'};
            if (!updateBoard(Board, moveIndexes, PlayerCharacter))
            {
                cout << "Wrong indices!" << endl;
                Sleep(500);
            }
            else
            {
                unsigned char state = checkBoard(Board, PlayerCharacter);
                if (state == 2)
                {
                    PlayerCharacter = (PlayerCharacter == 'X' ? 'O' : 'X');
                    flagPlayer1Turn = !flagPlayer1Turn;
                }
                else
                {
                    flagEnd = true;
                    clearScreen();
                    if (state == 0)
                    {
                        cout << "State: DRAW";
                    }
                    else
                    {
                        cout << "State: Player" << (flagPlayer1Turn ? '1' : '2') << " " << '(' << PlayerCharacter << ')' << " WINS";
                    }
                    cout << endl
                         << endl;
                    displayBoard(Board);
                }
            }
        }

    } while (ask());
    return 0;
}

unsigned char checkBoard(char Board[3][3], char PlayerCharacter)
{
    unsigned char c = 2; // ongoing and 1 for win and 0 for draw

    // check rows
    for (int i = 0; i < 3 && c == 2; i++)
    {
        if ((Board[i][0] == PlayerCharacter) && (Board[i][0] == Board[i][1]) && (Board[i][1] == Board[i][2]))
            c = 1;
    }

    // check columns
    for (int j = 0; j < 3 && c == 2; j++)
    {
        if ((Board[0][j] == PlayerCharacter) && (Board[0][j] == Board[1][j]) && (Board[1][j] == Board[2][j]))
            c = 1;
    }

    // check diagonals
    if (Board[1][1] == PlayerCharacter)
    {
        if (((Board[0][0] == Board[1][1]) && (Board[1][1] == Board[2][2])) || ((Board[0][2] == Board[1][1]) && (Board[1][1] == Board[2][0])))
            c = 1;
    }

    // check draw
    bool flagDraw = true;
    for (int i = 0; i < 3 && flagDraw; i++)
    {
        for (int j = 0; j < 3 && flagDraw; j++)
        {
            if (!Board[i][j])
                flagDraw = false;
        }
    }
    if (flagDraw)
        c = 0;

    return c;
}

void displayBoard(char Board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << setw(5) << " " << (Board[i][0] ? Board[i][0] : ' ') << " | " << (Board[i][1] ? Board[i][1] : ' ') << " | " << (Board[i][2] ? Board[i][2] : ' ') << endl;
        if (i != 2)
            cout << setw(15) << string(11, '-') << endl;
    }
    cout << endl;
}

bool updateBoard(char Board[3][3], pair<int, int> moveIndexes, char PlayerCharacter)
{
    if (moveIndexes.first > 0 && moveIndexes.first < 4 && moveIndexes.second > 0 && moveIndexes.second < 4 && Board[moveIndexes.first - 1][moveIndexes.second - 1] == '\0')
        Board[moveIndexes.first - 1][moveIndexes.second - 1] = PlayerCharacter;
    else
        return false;
    return true;
}
