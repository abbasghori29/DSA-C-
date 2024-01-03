#include <iostream>
using namespace std;
class DoubleHashing {
private:
    int* table;
    int tableSize;
    int prime;
int hash1(int key) {
    return key % tableSize;
}

int hash2(int key) {
    return prime - (key % prime);
}

public:
  DoubleHashing(int size) {
    tableSize = size;
    table = new int[tableSize];
    for (int i = 0; i < tableSize; ++i) {
        table[i] = -1; // Initialize all elements to -1
    }
    prime = 7; // Choose a prime number for hash2
}
void display() {
    cout << "Hash Table:" << endl;
    for (int i = 0; i < tableSize; ++i) {
        if (table[i] != -1) {
            cout << i << ": " << table[i] <<endl;
        }
    }
}
void insert(int key) {
    int index = hash1(key);
    int step = hash2(key);

    while (table[index] != -1) {
        index = (index + step) % tableSize;
    }

    table[index] = key;
}

bool search(int key) {
    int index = hash1(key);
    int step = hash2(key);

    while (table[index] != -1) {
        if (table[index] == key) {
            return true;
        }
        index = (index + step) % tableSize;
    }

    return false;
}

void remove(int key) {
    int index = hash1(key);
    int step = hash2(key);

    while (table[index] != -1) {
        if (table[index] == key) {
            table[index] = -1; // Mark the slot as deleted
            return;
        }
        index = (index + step) % tableSize;
    }
}
};


int main() {
    DoubleHashing hashTable(10);
    hashTable.insert(5);
    hashTable.insert(25);
    hashTable.insert(15);
    hashTable.insert(35);
    hashTable.insert(45);

    hashTable.display();

    if (hashTable.search(15)) {
        cout << "Key 15 found in the hash table." << endl;
    } else {
        cout << "Key 15 not found in the hash table." << endl;
    }

    hashTable.remove(25);
    hashTable.display();
}

