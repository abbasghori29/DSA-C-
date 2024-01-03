#include<iostream>
using namespace std;
template <typename T>
struct Node{
	T data;
	Node *next;
	Node(T val):data(val),next(NULL){}
};
template <typename T>
class Stack{
	private:
	Node<T> * head;
	int len;
	public:
	Stack(){
		head=NULL;
		len=0;
	}
	void push(int d){
		Node <T> *newNode = new Node<T>(d);
		if(head==NULL){
			head=newNode;
			len++;
		}
		else{
			newNode->next=head;
			head=newNode;
			len++;
		}
	}
	bool isEmpty(){
		return (head==NULL);
	}
	T pop(){
		if(!isEmpty()){
			T dt=head->data;
			head=head->next;
			len--;
			return dt;
		}
		else{
			cout<<"Stack Is Already Empty!";
			return T();
		}
	}
	T peek(){
			if(!isEmpty()){
			return head->data;;
		}
		else{
			cout<<"Stack Is Empty!";
			return T();
		}
	}
	int size(){
		return len;
	}
	
};
int main(){
	Stack <int> s;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	int n=s.size();
	for (int i =0;i<n;i++){
		cout<<"\n"<<s.pop();
	}
}
