#include <iostream>
using namespace std;

const int tableSize = 10;

class HashTable {
private:
    int table[tableSize];
public:
    HashTable() {
        for (int i = 0; i < tableSize; ++i) {
            table[i] = -1;
        }
    }

    int hashFunction(int key) {
        return key % tableSize;
    }

    void insert(int key) {
        int index = hashFunction(key);

        while (table[index] != -1) {
            index = (index + 1) % tableSize;
        }

        table[index] = key;
    }

    bool search(int key) {
        int index = hashFunction(key);

        while (table[index] != -1) {
            if (table[index] == key) {
                return true;  // Key found
            }

            index = (index + 1) % tableSize;
        }

        return false;  // Key not found
    }

    void display() {
        for (int i = 0; i < tableSize; ++i) {
            cout << "Index " << i << ": ";
            if (table[i] != -1) {
                cout << table[i];
            } else {
                cout << "Empty";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;

    hashTable.insert(5);
    hashTable.insert(25);
    hashTable.insert(15);
    hashTable.insert(35);
    hashTable.insert(10);

    cout << "Hash Table after insertion:" << endl;
    hashTable.display();

    int searchKey = 15;
    if (hashTable.search(searchKey)) {
        cout << "Key " << searchKey << " found in the hash table." << endl;
    } else {
        cout << "Key " << searchKey << " not found in the hash table." << endl;
    }

}

