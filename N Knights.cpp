#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to place a knight at position (x, y)
bool isSafe(vector<vector<int> >& board, int x, int y, int N) {
    // Check if the position is inside the board
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}

// Function to solve the N-Knights problem using backtracking
bool solveNKnights(vector<vector<int> >& board, int N, int row, int col, int knightsPlaced) {
    // If all knights are placed, return true
    if (knightsPlaced == N * N) {
        return true;
    }

    // Possible moves for a knight
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Try placing a knight in all possible positions
    for (int i = 0; i < 8; i++) {
        int newX = row + dx[i];
        int newY = col + dy[i];

        if (isSafe(board, newX, newY, N)) {
            board[newX][newY] = knightsPlaced;
            if (solveNKnights(board, N, newX, newY, knightsPlaced + 1)) {
                return true; // If a solution is found, return true
            }
            // If no solution is found, backtrack and try the next move
            board[newX][newY] = -1;
        }
    }

    return false; // If no valid move is found, return false
}

// Function to solve the N-Knights problem and print the board
void solveNKnights(int N) {
    vector<vector<int> > board(N, vector<int>(N, -1));

    // Start with the first knight at position (0, 0)
    board[0][0] = 0;

    if (solveNKnights(board, N, 0, 0, 1)) {
        // Print the solution
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }
}

int main() {
    int N;
    cout << "Enter the size of the chessboard (N x N): ";
    cin >> N;

    solveNKnights(N);

    return 0;
}

