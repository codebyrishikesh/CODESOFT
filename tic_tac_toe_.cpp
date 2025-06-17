#include <iostream>
using namespace std;

char board[3][3]; 
char currentPlayer; 
void resetBoard() {
    char cell = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = cell++;
        }
    }
    currentPlayer = 'X'; 
}

void displayBoard() {
    cout << "\n";
    cout << "     Tic-Tac-Toe" << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  ";
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        if (i < 2) cout << "\n ----|----|----\n";
    }
    cout << "\n---------------------\n";
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool makeMove(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    if (cell < 1 || cell > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false; 
    } else {
        board[row][col] = currentPlayer;
        return true;
    }
}


bool checkWin() {
    
    for (int i = 0; i < 3; i++) {
        
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer) {
            return true;
        }
    
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer) {
            return true;
        }
    }
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer) {
        return true;
    }

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer) {
        return true;
    }

    return false;
}


bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    char playAgain;

    do {
        resetBoard(); 
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();
            int cell;
            cout << "Player " << currentPlayer << ", enter a number (1-9) to make your move: ";
            cin >> cell;

            if (!makeMove(cell)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "?? Player " << currentPlayer << " wins! Congratulations!\n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw! ?? Well played both.\n";
                gameOver = true;
            } else {
                switchPlayer(); 
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing Tic-Tac-Toe! ?? Goodbye!\n";
    return 0;
}

