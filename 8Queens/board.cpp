#include "board.h"

Board::Board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = '-';
        }
    }
    
}

void Board::printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool Board::isSafe(int row, int col) {
    int i,j;
    for (i = 0; i < col; i++) {
        if (board[row][i] == 'Q')
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
 
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}
    
void Board::place(int row, int col) {
    assert(row < N && col < N);
    board[row][col] = 'Q';
}

void Board::unplace(int row, int col) {
    assert(row < N && col < N);
    board[row][col] = '-';
}
