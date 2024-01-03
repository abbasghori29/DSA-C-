#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<int> >& inp, vector<vector<int> >& visited, int n) {
    if (x < n  && y < n && inp[x][y]==1) {
        return true;
    } 
    else {
        return false;
    }
}

bool ratInMaze(int x, int y, vector<vector<int> >& inp, vector<vector<int> >& visited, int n) {
    if (x == n - 1 && y == n - 1) {
        visited[x][y] = 1;
        return true;
    }
    if (isSafe(x, y, inp, visited, n)) {
        visited[x][y] = 1;
        if (ratInMaze(x + 1, y, inp, visited, n)) {
            return true;
        }
        if (ratInMaze(x, y + 1, inp, visited, n)) {
            return true;
        }
        visited[x][y] = 0; // Backtracking
        return false;
    }
    return false;
}

int main() {
    int r =5; // Number of rows
    int c = 5; // Number of columns
    int i, j;
    
    int arr[r][c]= {  {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1}};
    vector<vector<int> > inp(r, vector<int>(c)); 
    for(i=0;i<r;i++){
    	for(j=0;j<c;j++){
    		inp[i][j]=arr[i][j];
		}
    	
	}
    

    vector<vector<int> > ans(r, vector<int>(c, 0)); // Initialize ans with correct size and fill with 0s
    ratInMaze(0, 0, inp, ans, r);
    
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

