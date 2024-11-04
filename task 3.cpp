



#include <iostream>
using namespace std;

char board[3][3];  
char currentPlayer; 

void initializeBoard() {
    
    int count = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '0' + count;
            count++;
        }
    }
}

void displayBoard() {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|"; 
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";  
    }
    cout << endl;
}

bool checkWin() {
    
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }

    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

bool checkDraw() {
   
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;

    return true;
}

void switchPlayer() {
   
    if (currentPlayer == 'X') currentPlayer = 'O';
    else currentPlayer = 'X';
}

bool makeMove(int position) {
    
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

   
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        cout << "Position already taken. Try again!\n";
        return false;
    }
}

int main() {
    char playAgain;
    do {
        initializeBoard();
        currentPlayer = 'X';  
        bool gameWon = false;
        bool gameDraw = false;

        while (!gameWon && !gameDraw) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            int move;
            cin >> move;

            
            if (move >= 1 && move <= 9 && makeMove(move)) {
              
                gameWon = checkWin();
                gameDraw = checkDraw();

                if (!gameWon && !gameDraw) {
                    switchPlayer();  
                }
            } else {
                cout << "Invalid move! Please enter a valid position (1-9).\n";
            }
        }

        displayBoard();
        if (gameWon) {
            cout << "Player " << currentPlayer << " wins! Congratulations!\n";
        } else if (gameDraw) {
            cout << "It's a draw!\n";
        }

        // Ask if the players want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;
    return 0;
}
