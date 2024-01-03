#include<iostream>
#include<string>
using namespace std;
struct Node{
	string data;
	Node *prev;
	Node *next;
	Node(string val): data(val),prev(NULL),next(NULL){}
};
class DoublyLinkedList{
	private:
		Node *head;
		Node *tail;
		int ListLength;
	public:
	DoublyLinkedList(){
		head=NULL;
		tail=NULL;
		ListLength=0;
	}
	void prepend(string n){
		Node *newNode = new Node(n);
		if(head==NULL){
			head=newNode;
			tail=newNode;
			ListLength++;
		}
		else{
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
			ListLength++;
		}
	}
	void append(string n){
		Node *newNode= new Node(n);
		if(head==NULL){
		  head=newNode;
		  tail=newNode;
		  ListLength++;
		}
		else{
			tail->next=newNode;
			newNode->prev=tail;
			tail=newNode;
			ListLength++;
		}
		
	}
	void insertAfter(int index,string val){
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
		ListLength++;
		
	}
	void removeNodeAt(int index){
		Node *temp=head;
		int count=1;
		while(temp->next!=NULL && count<index){
			temp=temp->next;
			count++;
		}
		Node *nodeTBD=temp->next;
		Node *after=nodeTBD->next;
		temp->next=after;
		after->prev=temp;
		delete nodeTBD;
		
	}
void reverseKnodes(int k) {
  Node* current = head;

while (current) {
    Node* node1 = current;
    Node* node2 = current;

    int count = 1;
    while (count < k) {
        node2 = node2->next;
        count++;
    }

    if (!node2) {
        break;
    }
	    
    string temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
    
    current = node2->next;
}


}

	void printList(){
		Node *temp=head;
		while(temp->next!=NULL){
			cout<<"\n"<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n"<<temp->data<<" ";
	}
};

int main(){
	DoublyLinkedList l1;
	l1.append("I Am Paragraph 1");
	l1.append("I Am Paragraph 2");
	l1.append("I Am Paragraph 3");
	l1.append("I Am Paragraph 4");
	l1.append("I Am Paragraph 5");
	l1.append("I Am Paragraph 6");
	l1.append("I Am Paragraph 7");
	l1.append("I Am Paragraph 8");
	l1.append("I Am Paragraph 9");
	cout<<"Paragraphs Before Reversing K Nodes: \n";
	l1.printList();
	l1.reverseKnodes(2);
	cout<<"\n\nParagraphs After Reversing K Nodes: \n";
	l1.printList();
	
	
	
}
