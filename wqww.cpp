#include <iostream>
#include <vector>
using namespace std;
const int ROWS = 3;
const int COLS = 4;

int maze[3][4] = {
    {1, 0, 0, 1},
    {0, 1, 1, 1},
    {0, 1, 1, 0}
};

// Function to check if a cell is a valid move
bool isSafe(int row, int col, const std::vector<std::vector<int> >& visited) {
    return (row >= 0 && col >= 0 && row < ROWS && col < COLS && maze[row][col] == 1 && !visited[row][col]);
}


// Recursive function to find the optimal path
bool findPath(int row, int col, std::vector<std::vector<int> >& visited, std::vector<std::pair<int, int> >& path) {
    // If we have reached the destination
    if (row == 0 && col == COLS - 1) {
        path.push_back({row, col});
        return true;
    }

    // Mark the current cell as visited
    visited[row][col] = 1;

    // Possible moves: right, down, up, left
    int dr[] = {0, 1, -1, 0};
    int dc[] = {1, 0, 0, -1};
    char direction[] = {'R', 'D', 'U', 'L'};

    // Try all possible moves
    for (int i = 0; i < 4; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        if (isSafe(newRow, newCol, visited)) {
            path.push_back({row, col});
            if (findPath(newRow, newCol, visited, path))
                return true;
            path.pop_back(); // Backtrack if the path is not valid
        }
    }

    // Mark the current cell as unvisited before backtracking
    visited[row][col] = 0;

    return false;
}

int main() {
    std::vector<std::vector<int> > visited(ROWS, std::vector<int>(COLS, 0));
    std::vector<std::pair<int, int> > path;

    findPath(0, 0, visited, path);
    for(int i=0;i<3;i++){
    	for(int j=0;j<4;j++){
    		cout<<visited[i][j];
		}
	}

    return 0;
}

