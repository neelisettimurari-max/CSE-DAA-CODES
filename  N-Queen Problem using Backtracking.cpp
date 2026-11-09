
#include <iostream>
using namespace std;

int board[20][20];
int n;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueen(int row) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            if (solveNQueen(row + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    cout << "Enter the value of N: ";
    cin >> n;

    if (n < 1 || n > 20) {
        cout << "Enter N between 1 and 20.";
        return 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    if (solveNQueen(0)) {
        cout << "Solution:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists.";
    }

    return 0;
}

