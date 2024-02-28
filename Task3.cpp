#include <iostream>
#include <vector>
using namespace std;
class TicTacToe 
{
public:
    TicTacToe() 
    {
        for (int i = 0; i < 9; i++) 
        {
            board[i] = ' ';
        }
        current_player = 'X';
    }

    void display_board() 
    {
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                cout << board[i * 3 + j] << ' ';
            }
            cout << '\n';
        }
    }

    int player_input() 
    {
        int move;
        while (true) 
        {
            cout << "Player " << current_player << ", enter your move (1-9): ";
            cin >> move;
            if (move >= 1 && move <= 9 && board[move - 1] == ' ') 
            {
                return move - 1;
            } 
            else 
            {
                cout << "Invalid move." << '\n';
            }
        }
    }

    bool check_win() 
    {
        for (int i = 0; i < 3; i++) 
        {
            if (board[i * 3] == board[i * 3 + 1] && board[i * 3] == board[i * 3 + 2] && board[i * 3] != ' ') 
            {
                return true;
            }
            if (board[i] == board[i + 3] && board[i] == board[i + 6] && board[i] != ' ') 
            {
                return true;
            }
        }
        if (board[0] == board[4] && board[0] == board[8] && board[0] != ' ') 
        {
            return true;
        }
        if (board[2] == board[4] && board[2] == board[6] && board[2] != ' ') 
        {
            return true;
        }
        return false;
    }

    bool check_draw() 
    {
        for (int i = 0; i < 9; i++) 
        {
            if (board[i] == ' ') 
            {
                return false;
            }
        }
        return true;
    }

    void switch_players() 
    {
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    void play() 
    {
        while (true) 
        {
            display_board();
            int move = player_input();
            board[move] = current_player;
            if (check_win()) {
                display_board();
                cout << "Player " << current_player << " wins!" << '\n';
                break;
            } 
            else if (check_draw()) 
            {
                display_board();
                cout << "It's a draw!" << '\n';
                break;
            } 
            else 
            {
                switch_players();
            }
        }
        while (true) 
        {
            string play_again;
            cout << "Do you want to play again? (yes/no): ";
            cin >> play_again;
            if (play_again == "yes") 
            {
                for (int i = 0; i < 9; i++) 
                {
                    board[i] = ' ';
                }
                current_player = 'X';
                break;
            } 
            else if (play_again == "no") 
            {
                cout << "Thanks for playing!" << '\n';
                break;
            } 
            else 
            {
                cout << "Invalid input." << '\n';
            }
        }
    }

private:
    char board[9];
    char current_player;
};

int main() 
{
    cout<<"\t\t\t\t\t\t\t\tTIC TAC TOE";
    TicTacToe game;
    game.play();
    return 0;
}