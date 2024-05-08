
#include <iostream>
#include <conio.h>
#include <ctime>
#include <random>
using namespace std;
class Tic_Tac_Toe
{
public:
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    void show_board();
    void get_x_player_choice();
    void get_o_player_choice();
    void get_computer_choice();
    int count_board(char symbol);
    char check_winner();
    void computer_vs_player();
    void player_vs_player();
};

void Tic_Tac_Toe::show_board()
{
    cout << "TIC TAC TOE GAME." << endl;
    cout << endl;
    cout << "   "
         << "   |   "
         << "   |   " << endl;
    cout << "   " << board[0] << "  |   " << board[1] << "  |   " << board[2] << endl;
    cout << "   "
         << "   |   "
         << "   |   " << endl;
    cout << "--------------------" << endl;
    cout << "   "
         << "   |   "
         << "   |   " << endl;
    cout << "   " << board[3] << "  |   " << board[4] << "  |   " << board[5] << endl;
    cout << "   "
         << "   |   "
         << "   |   " << endl;
    cout << "--------------------" << endl;
    cout << "   "
         << "   |   "
         << "   |   " << endl;
    cout << "   " << board[6] << "  |   " << board[7] << "  |   " << board[8] << endl;
    cout << "   "
         << "   |   "
         << "   |   " << endl;
}
void Tic_Tac_Toe::get_x_player_choice()
{
    while (true)
    {
        cout << "Select Your Position(1 - 9): ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8)
        {
            cout << "Please Select Your Choice From (1 to 9): " << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << "Please Select An Empty Position: " << endl;
        }
        else
        {
            board[choice] = 'x';
            break;
        }
    }
}
void Tic_Tac_Toe::get_o_player_choice()
{
    while (true)
    {
        cout << "Select Your Position(1 - 9): ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8)
        {
            cout << "Please Select Your Choice From (1 to 9): " << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << "Please Select An Empty Position: " << endl;
        }
        else
        {
            board[choice] = 'o';
            break;
        }
    }
}
void Tic_Tac_Toe::get_computer_choice()
{
    srand(time(0));
    int choice;
    do
    {
        choice = rand() % 10;
    }

    while (board[choice] != ' ');
    board[choice] = 'o';
}

int Tic_Tac_Toe::count_board(char symbol)
{
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == symbol)
            total += 1;
    }
    return total;
}
char Tic_Tac_Toe::check_winner()
{
    // checking winner in horizontal/row
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0];
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];

    // checking winner in vertical / column
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        return board[0];
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];

    // checking winner in diagonal
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];
    if (count_board('x') + count_board('o') < 9)
    {
        return 'C';
    }
    else
    {
        return 'D';
    }
}
void Tic_Tac_Toe::player_vs_player()
{
    string x_player_name, o_player_name;
    cout << "Enter x Player Name: ";
    cin >> x_player_name;
    cout << " Enter o Player Name: ";
    cin >> o_player_name;
    while (true)
    {
        system("cls");
        show_board();
        if (count_board('x') == count_board('o'))
        {
            cout << x_player_name << "'s turn." << endl;
            get_x_player_choice();
        }
        else
        {
            cout << o_player_name << "'s turn." << endl;
            get_o_player_choice();
        }
        char winner = check_winner();
        if (winner == 'x')
        {
            system("cls");
            show_board();
            cout << x_player_name << " Won the Game." << endl;
            break;
        }
        else if (winner == 'o')
        {
            system("cls");
            show_board();
            cout << o_player_name << " Won the Game." << endl;
            break;
        }
        else if (winner == 'D')
        {
            cout << "Game is Draw." << endl;
            break;
        }
    }
}
void Tic_Tac_Toe::computer_vs_player()
{
    string player_name;
    cout << "Enter Your Name: ";
    cin >> player_name;
    while (true)
    {
        system("cls");
        show_board();
        if (count_board('x') == count_board('o'))
        {
            cout << player_name << "'s turn." << endl;
            get_x_player_choice();
        }
        else
        {
            get_computer_choice();
        }
        char winner = check_winner();
        if (winner == 'x')
        {
            system("cls");
            show_board();
            cout << player_name << " Won The Game." << endl;
            break;
        }
        else if (winner == 'o')
        {
            system("cls");
            show_board();
            cout << " Computer Won the Game ." << endl;
            break;
        }
        else if (winner == 'D')
        {
            cout << "Game is Draw." << endl;
            break;
        }
    }
}


int main()
{
    Tic_Tac_Toe ttt;
    int mode;
    cout << "1. Computer vs Player." << endl;
    cout << "2. Player vs Player" << endl;
    cout << "Select Game Mode." << endl;
    cin >> mode;
    switch (mode)
    {
    case 1:
        ttt.computer_vs_player();
        break;
    case 2:
        ttt.player_vs_player();
        break;
    default:
        cout << "Please Select Valid Game Mode." << endl;
        break;
    }
    ttt.show_board();
    getch();
}



