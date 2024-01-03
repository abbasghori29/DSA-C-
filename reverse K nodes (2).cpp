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
			
		Node* reverseK(Node* head, int k) {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        int count = 0;        
            while (current != NULL && count <k-(k-1)) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count++;
            }
            if (next != NULL) {
                head->next = reverseK(next, k);
            }

        return prev;
    }
    void reverseK(int k) {
        head = reverseK(head, k);
    }

			
};
int main(){
	int i;
	LinkedList l1 ;
	l1.append(9);
	l1.append(2);
	l1.append(3);
	l1.append(4);
	l1.append(5);
	l1.append(6);
l1.reverseK(2);
	for(i=0;i<l1.length()-1;i++){
		cout<<l1.get(i)<<" ";
	}
	
}
