#include<iostream>
using namespace std;
class circularQueue{
	int arr[5];
	int size;
	int rear,front;
	public:
		circularQueue(){
			size=5;
			rear=front=-1;
		}
		bool isFull(){
		return ((front==0 && rear==size-1) || (rear==(front-1)%(size)));
		}
		bool isEmpty(){
			return(front==-1);
		}
		void enqueue(int data){
			if(isFull()){
				cout<<"Queue Is Full Can't Push More Elements";
				return;
			}
			else if(front == -1){
				front=rear=0;
			}
			else if (front != 0 && rear == size - 1) {
              rear = 0;
            }
			else {
				rear++;
			}
			arr[rear]=data;
		}
		int dequeue(){
			if(isEmpty()){
				cout<<"Queue is All empty!!!";
				return -1;
			}
			int ans=arr[front];
			if(front==rear){
				front=rear=-1;
			}
			else if(front==size-1){
				front = 0;
			}
			front++;
			return ans;
		}
		void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    int i = front;
    if (front <= rear) {
        while (i <= rear) {
            cout << arr[i] << " ";
            i++;
        }
    } else {
        while (i < size) {
            cout << arr[i] << " ";
            i++;
        }
        i = 0;
        while (i <= rear) {
            cout << arr[i] << " ";
            i++;
        }
    }
    cout << endl;
}

};
int main(){
	circularQueue c;
	c.enqueue(1);
	c.enqueue(2);
	c.enqueue(3);
	c.enqueue(4);
	c.display();
	
}
