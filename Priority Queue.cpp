#include<iostream>
#include<string>
using namespace std;
class Task {
public:
    string task;
    int taskn;
    Task() : task(""), taskn(-1) {} 
    Task(string task, int taskn) {
        this->task = task;
        this->taskn = taskn;
    }
};

class Queue{
		public:
			Task arr[5];
		int rear;
		int front;
			Queue(){
				front=-1;
				rear=-1;
			}
void enqueue(string task, int taskn) {
    if (rear == 4) {
        cout << "Queue is already full!" << endl;
        return;
    }

    Task t(task, taskn); // Create a Task object
    rear++;

    arr[rear] = t; 
    int index = rear;

    while (index > 0) {
        int parent = (index - 1) / 2;

        if (arr[parent].taskn > arr[index].taskn) {
            swap(arr[parent], arr[index]);
            index = parent;
        } else {
            break;
        }
    }
}

Task dequeue() {
    if (front == rear) {
        cout << "Heap is already empty!" ;
        return Task("", -1); 
    }
    front++;
    Task t = arr[0]; 
    arr[0] = arr[rear]; 
    rear--;

    int index = 0;
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild <= rear && arr[leftChild].taskn < arr[smallest].taskn) {
            smallest = leftChild;
        }

        if (rightChild <= rear && arr[rightChild].taskn < arr[smallest].taskn) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(arr[index], arr[smallest]);
            index = smallest;
        } else {
            break;
        }
    }

    return t;
}

};
int main(){
	Queue q;
	q.enqueue("abc",3);
	q.enqueue("def",5);
	q.enqueue("ghi",188);
	q.enqueue("jkl",12);
	q.enqueue("mno",7);
	for(int i=0;i<5;i++){
		Task t = q.dequeue();
		cout<<"\n"<<t.task<<" : "<<t.taskn;
	}
}
