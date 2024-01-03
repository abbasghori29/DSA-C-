#include <iostream>
using namespace std;

struct Node {
    Node* next;
    int data;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void deleteNode(int val) {
        Node* prev = NULL;
        Node* current = head;

        while (current != NULL && current->data != val) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) return;

        if (prev == NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    void insertAfterValue(int valueToFind, int val) {
        Node* temp = head;

        while (temp != NULL && temp->data != valueToFind) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Value " << valueToFind << " not found in the list.\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void reverse() {
        Node *prev = NULL, *current = head, *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void concatenate(LinkedList& list2) {
        if (head == NULL) {
            head = list2.head;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = list2.head;
    }
};

int main() {
    LinkedList list;
    list.insert(3);
    list.insert(5);
    list.insert(7);

    cout << "Original List: ";
    list.print();

    list.deleteNode(5);
    cout << "After deleting 5: ";
    list.print();

    list.insertAfterValue(3, 10);
    cout << "After inserting 10 after the first occurrence of 3: ";
    list.print();

    cout << "Reversed List: ";
    list.reverse();
    list.print();

    LinkedList list2;
    list2.insert(2);
    list2.insert(4);
    list2.insert(6);

    cout << "Second List: ";
    list2.print();

    list.concatenate(list2);
    cout << "Concatenated List: ";
    list.print();

    return 0;
}

