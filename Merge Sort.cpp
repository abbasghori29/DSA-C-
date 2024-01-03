#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int>& first, vector<int>& second) {
    vector<int> mix;
    int i = 0, j = 0;

    while (i < first.size() && j < second.size()) {
        if (first[i] < second[j]) {
            mix.push_back(first[i]);
            i++;
        } else {
            mix.push_back(second[j]);
            j++;
        }
    }

    while (i < first.size()) {
        mix.push_back(first[i]);
        i++;
    }

    while (j < second.size()) {
        mix.push_back(second[j]);
        j++;
    }

    return mix;
}

vector<int> mergeSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return arr;
    }

    int mid = n / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    vector<int> arr ;
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    vector<int> sortedArr = mergeSort(arr);

    for (int i = 0; i < sortedArr.size(); i++) {
        cout << sortedArr[i] << " ";
    }
    

    return 0;
}

