#include <iostream>
#include <cassert>
using namespace std;

const int N = 8;

class Board {
    public:
        Board();
        bool isSafe(int row, int col);
        void place(int row, int col);
        void unplace(int row, int col);
        void printBoard();
    private:
        char board[N][N];
};