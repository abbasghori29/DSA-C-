#include<iostream>
using namespace std;
class Queue{
	public:
		int arr[100];
		int size=100;
	    int front;
	    int rear;
	    Queue(){
	    	front=0;
	    	rear=0;
		}
	void enqueue(int data){
		if(rear<size){
			arr[rear]=data;
			rear++;
		}
		else{
			cout<<"Queue Is Full";
		}
	}
	int dequeue(){
		if(!isEmpty()){
			int d=arr[front];
			front++;
			if(front==rear){
				front=rear=-1;
			}
			return d;
		}
	}
	bool isEmpty(){
		return (front==-1);
	}
};
int main(){
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	for(int i=0;i<4;i++){
		cout<<q.dequeue();
	}
}
