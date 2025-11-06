#include <iostream>
using namespace std;

int N = 8; // size of chessboard
int board[8][8]; // fixed-size array since N = 8

// Function to print the chessboard
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Backtracking function to place queens
bool solve(int row) {
    if (row == N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            if (solve(row + 1))
                return true;

            board[row][col] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    // Initialize board with 0
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    // Place the first queen manually
    board[0][0] = 1;

    // Solve for remaining queens
    if (solve(1))
        printBoard();
    else
        cout << "No solution exists\n";

    return 0;
}

