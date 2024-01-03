#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *prev;
	Node *next;
	Node(int val): data(val),prev(NULL),next(NULL){}
};
class LinkedList{
	public:
		Node *head;
		Node *tail;
		int len;
	LinkedList(){
		head=NULL;
		tail=NULL;
		len=0;
	}
	void append(int d){
		Node *newNode = new Node(d);
		if(head==NULL){
			head=newNode;
			tail=newNode;
			len++;
		}
		else{
			tail->next=newNode;
			newNode->prev=tail;
			tail=newNode;
			len++;
		}
	}
	void prepend(int d){
		Node *newNode = new Node(d);
		if(head==NULL){
			head=newNode;
			tail=newNode;
			len++;
		}
		else{
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
			len++;
		}
	}
	void insertAfter(int ind , int d){
		Node *newNode = new Node(d);
		Node *temp=head;
		int count=0;
		while(count<ind && temp->next!=NULL){
			temp=temp->next;
			count++;
		}
		newNode->next=temp->next;
		temp->next->prev=newNode;
		temp->next=newNode;
		newNode->prev=temp;
		len++;
	}
	void remove(int ind){
		Node *temp=head;
		int cnt=0;
		if(ind==0){
			Node *tbd=head;
			head=head->next;
			delete tbd;
			len--;
		}
		else if(ind==len-1){
			Node *tt=tail;
			tail=tail->prev;
			tail->next=NULL;
			delete tt;
			len--;
		}
		else{
			while(temp->next!=NULL && cnt<ind-1){
			temp=temp->next;
			cnt++;
		}
		Node *tbd=temp->next;
		temp->next=tbd->next;
		tbd->next->prev=temp;
		delete tbd;
		len--;
		}
		
		
		
	}
	void print(){
		Node *temp=head;
		while(temp->next!=NULL){
			cout<<temp->data;
			temp=temp->next;
		}
		cout<<temp->data;
	}
};
int main(){
	LinkedList l;
	l.append(1);
	l.append(2);
	l.append(3);
	l.append(4);
//	l.prepend(5);
//	l.prepend(6);
//	l.insertAfter(0,7);
	l.remove(3);
	l.print();
}
