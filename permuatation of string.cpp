#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permutations(vector<string> inp, vector<vector<string> > &ans, int index) {
    if (index >= inp.size()) {
        ans.push_back(inp);
    }
    for (int i = index; i < inp.size(); i++) {
        swap(inp[i], inp[index]);
        permutations(inp, ans, index + 1);
        // Backtrack
        swap(inp[i], inp[index]);
    }
}

int main() {
    vector<string> inp;
    vector<vector<string> > ans;
    inp.push_back("a");
    inp.push_back("b");
    inp.push_back("c");
    permutations(inp, ans, 0);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

