#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int val) : data(val) ,next(NULL){}
};
class LinkedList{
        public:
		    Node *head;
			LinkedList(){
			head=NULL;
		}
			void append(int val){
				Node *newNode = new Node(val);
				if(head==NULL){
					head=newNode;
				}
				else{
					Node *temp=head;
					while(temp->next!=NULL){
						temp=temp->next;
					}
					temp->next=newNode;
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
Node *reverseK(Node* &head ,int k){
	Node *current=head;
	Node *prev=NULL;
	Node *next=NULL;
	int count=0;
	while(current->next!=NULL && count<k){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}
	if(next!=NULL){
		head->next=reverseK(next,k);
	}
	
	head=prev;
	return head;
}
int main(){
	int i;
	LinkedList l1 ;
	l1.append(9);
	l1.append(2);
	l1.append(3);
	l1.append(4);
	l1.append(5);
	l1.append(6);
reverseK(l1.head,2);
	
	l1.print();
}
