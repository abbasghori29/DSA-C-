#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node *prev;
	
	Node(int val):data(val),next(NULL),prev(NULL){}
};
class linklist{
	public:
		Node *head;
		Node *tail;
		int len;
		linklist(){
			head=NULL;
			tail=NULL;
			len=0;
		}
		void append(int d){
			Node *newNode= new Node(d);
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
		
		
		void print(){
		Node *temp=head;
		while(temp->next!=NULL){
			cout<<temp->data;
			temp=temp->next;
		}
		cout<<temp->data;
	}

		
};
Node *reverseKnodes(Node * &head, int k) {
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;

    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL) {
        head->next = reverseKnodes(next, k);
    }
    head = prev;

    return head;
}

int main(){
linklist l;
l.append(1);
l.append(2);
l.append(3);
l.append(4);
l.append(5);
l.append(6);
reverseKnodes(l.head,2);
l.print();	
}
