#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() : front(NULL), rear(NULL) {}

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return -1;
        }
        int data = front->data;
        if (front == rear) {
            delete front;
            front = NULL;
            rear = NULL;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
        return data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* current = front;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
    
    }
};

int main() {
    CircularQueue queue;

    // Enqueue some elements
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // Display the queue
    queue.display();  // Output: 1 2 3

    // Dequeue elements
    cout << "Dequeue: " << queue.dequeue() << ;  // Output: Dequeue: 1
    cout << "Dequeue: " << queue.dequeue() << ;  // Output: Dequeue: 2

    // Display the queue after dequeuing
    queue.display();  // Output: 3

    return 0;
}

