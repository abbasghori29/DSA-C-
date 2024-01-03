#include <iostream>
using namespace std;
// Node structure for linked list at each hash index
struct Node {
    int key;
    int value;
    Node* next;
    Node(int k, int v) : key(k), value(v), next(NULL) {}
};

// HashTable class
class HashTable {
private:
    static const int tableSize = 10;  // Size of the hash table
    Node* table[tableSize];           // Array of pointers to Node

    // Hash function to determine index
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    // Constructor
    HashTable() {
        for (int i = 0; i < tableSize; ++i) {
            table[i] = NULL;
        }
    }

    // Insert a key-value pair into the hash table
    void insert(int key, int value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);

        // If the index is empty, insert the new node
        if (table[index] == NULL) {
            table[index] = newNode;
        }
        // If the index is not empty, handle collision by chaining
        else {
            Node* current = table[index];
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Delete a specific key-value pair from the hash table
    void remove(int key, int value) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* previous = NULL;

        // Search for the key-value pair in the linked list
        while (current != NULL && (current->key != key || current->value != value)) {
            previous = current;
            current = current->next;
        }

        // If the key-value pair is found, delete the node
        if (current != NULL) {
            if (previous == NULL) {
                // If the node to be deleted is the first in the list
                table[index] = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
        }
    }

    // Print all keys and their associated values
    void printAllValues() {
        for (int i = 0; i < tableSize; ++i) {
            Node* current = table[i];
            cout << "At Key " << i << " Values: ";

            while (current != NULL) {
                cout << current->value << " ";
                current = current->next;
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable myHashTable;

    // Insert some key-value pairs
    myHashTable.insert(1, 10);
    myHashTable.insert(2, 20);
    myHashTable.insert(3, 30);
    myHashTable.insert(2, 40); // Collision with key 2

    // Print all values before removal
    cout << "Before Removal:" <<endl;
    myHashTable.printAllValues();

    // Remove a specific key-value pair
    myHashTable.remove(2, 20);

    // Print all values after removal
    cout << "After Removal:" <<endl;
    myHashTable.printAllValues();
}

