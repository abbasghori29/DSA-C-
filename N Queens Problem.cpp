#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int> >& board, int row, int col, int N) {
    // Check the left side of the current column
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check the upper left diagonal
    int i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }

    // Check the lower left diagonal
    i = row, j = col;
    while (i < N && j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

bool solveNQueens(vector<vector<int> >& board, int col, int N) {
    if (col >= N) {
        // All queens are placed successfully
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1, N)) {
                return true;
            }

            // If placing a queen in board[i][col] doesn't lead to a solution,
            // then backtrack and remove the queen from the current position.
            board[i][col] = 0;
        }
    }

    // If all rows have been tried and no solution is found, return false.
    return false;
}

void printSolution(vector<vector<int> >& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Enter the value of N (the size of the chessboard): ";
    cin >> N;

    vector<vector<int> > board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0, N)) {
        cout << "Solution exists:\n";
        printSolution(board, N);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}

