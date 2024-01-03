#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int prime = 101; 

int calculateHash(string str, int len) {
    int hash = 0;
    for (int i = 0; i < len; ++i) {
        hash += str[i] * pow(prime, i);
    }
    return hash;
}

int recalculateHash(int oldHash, char oldChar, char newChar, int len) {
    return (oldHash - oldChar) / prime + newChar * pow(prime, len - 1);
}

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int patternHash = calculateHash(pattern, m);
    int textHash = calculateHash(text, m);

    for (int i = 0; i <= n - m; ++i) {
        if (patternHash == textHash) {
    
            int j;
            for (j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == m) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        if (i < n - m) {
            textHash = recalculateHash(textHash, text[i], text[i + m], m);
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    rabinKarp(text, pattern);

    return 0;
}

