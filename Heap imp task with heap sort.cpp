#include<iostream>
using namespace std;
void heapifyMin(int *arr, int i, int n){
    int smallest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (rightChild < n && arr[rightChild] < arr[smallest]) {
        smallest = rightChild;
    }
    if (leftChild < n && arr[leftChild] < arr[smallest]) {
        smallest = leftChild;
    }
    if (smallest != i){
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, smallest, n);
    }
}

void heapifyMax(int *arr, int i, int n){
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }
    if (leftChild < n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, largest, n);
    }
}

void deleteRoot(int *arr, int &n){
    if (n == 0) {
        cout << "Heap Is Already Empty!";
        return;
    }
    arr[0] = arr[n - 1];
    n--;
    int parent = 0;
    while (parent <= n) {
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;
        if (left < n && arr[left] < arr[parent]) {
            swap(arr[left], arr[parent]);
            parent = left;
        } else if (right < n && arr[right] < arr[parent]) {
            swap(arr[right], arr[parent]);
            parent = right;
        } else {
            return;
        }
    }
}

void heapSort(int *arr, int n){
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(arr, i, n);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, 0, i);
    }
}

int main(){
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int n = sizeof(arr) / sizeof(arr[0]);
     cout<<"Given Tree: ";
     for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    // Making Min Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMin(arr, i, n);
    }
     cout<<"\n\nMin Heap Of Tree: ";
     for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
     
    // Deleting root node
    deleteRoot(arr, n);
    cout<<"\n\nTree After Deleting Root Node: ";
     for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
     // Making Max Heap of Updated Tree
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(arr, i, n);
    }
     cout<<"\n\nTree After Converting It To Max Heap : ";
     for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    // Now Sort The Heap Using Heap Sort
    heapSort(arr, n);
cout<<"\n\nSorted Tree After Converting It To Max Heap : ";
    // Printing the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

