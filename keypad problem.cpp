#include<iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string& digit, string output, int index, vector<string>& ans, const string mapping[]) {
    // Base case
    if (index >= digit.length()) {
        ans.push_back(output);
        return;
    }
    int number = digit[index] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++) {
        solve(digit, output + value[i], index + 1, ans, mapping); 
    }
}

int main() {
    vector<string> ans;
    string output;
    int index = 0;
    string digits = "23";
    const string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, index, ans, mapping);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

