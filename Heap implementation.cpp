#include<iostream>
using namespace std;
class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        size = -1;
    }

    void heapifyMax(int *arr, int i, int n) {
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

    void insert(int data) {
        size++;
        arr[size] = data;
        int index = size;
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[parent] <= arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 0; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap() {
        if (size == -1) {
            cout << "Heap Is Already Empty";
            return;
        }
        arr[0] = arr[size];
        size--;
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapifyMax(arr, i, size + 1);
        }
    }

    void heapSort() {
        int n = size + 1;
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyMax(arr, i, n);
        }
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapifyMax(arr, 0, i);
        }
    }
};

int main() {
    Heap heap;
    heap.insert(1);
    heap.insert(3);
    heap.insert(5);
    heap.insert(7);
    heap.insert(11);
    heap.insert(12);
    heap.insert(14);

    cout << "Original Heap: ";
    heap.print();

    heap.heapSort();

    cout << "Sorted Array: ";
    heap.print();

    return 0;
}

