#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int val) : data(val) ,next(NULL){}
};
class LinkedList{
	private:
		Node *head;
		int Listlength;
		
		public:
			LinkedList(){
			head=NULL;
			Listlength=1;
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
				
				Listlength++;
			}
			int get(int index){
				Node * temp=head;
				int count=0;
				while(count<index && temp->next!=NULL){
					temp=temp->next;
					count++;
				}
				return temp->data;
				
			}
			int length(){
				return this->Listlength;
			}
	void merge(LinkedList & l2){
		Node *temp;
		temp=this->head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=l2.head;
	}
		void display(){
			Node *temp=head;
			while(temp->next!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<temp->data<<" ";
		}	
};
int main(){
	int i;
	LinkedList l1 ;
	LinkedList l2 ;
	l1.append(9);
	l1.append(2);
	l1.append(3);
	l1.append(4);
	l1.append(5);
	l1.append(6);
	l2.append(91);
	l2.append(42);
	l2.append(33);
	l2.append(54);
	l2.append(52);
	l2.append(76);
	l1.merge(l2);
	l1.display();
	
}
