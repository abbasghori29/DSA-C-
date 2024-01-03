#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *prev;
	Node *next;
	Node(int val): data(val),prev(NULL),next(NULL){}
};
class DoublyLinkedList{
	private:
		Node *head;
		Node *tail;
		int len;
	public:
	DoublyLinkedList(){
		head=NULL;
		tail=NULL;
		len=0;
	}
	void prepend(int n){
		Node *newNode = new Node(n);
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
	void append(int n){
		Node *newNode= new Node(n);
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
	void insertAfter(int index,int val){
		Node *newNode = new Node(val);
		int count=0;
		Node *temp=head;
		while(temp->next!=NULL && count<index){
			temp=temp->next;
			count++;
		}
		newNode->next=temp->next;
		temp->next->prev=newNode;
		newNode->prev=temp;
		temp->next=newNode;
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
		void reverseLinkedList() {
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    tail = head;
    head = prev;
}
	void printList(){
		Node *temp=head;
		while(temp->next!=NULL){
			cout<<temp->data;
			temp=temp->next;
		}
		cout<<temp->data;
	}
};

int main(){
	DoublyLinkedList l1;
	l1.append(5);
	l1.append(4);
	l1.append(3);
	l1.append(2);
	l1.append(1);
	l1.insertAfter(1,9);
	l1.remove(3);
	l1.printList();
	
	
	
}
