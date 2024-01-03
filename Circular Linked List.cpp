#include<iostream>
#include<string>
using namespace std;
struct Node{
	string id;
	string name;
	string department;
	Node *next;
	Node(string i,string n,string d): id(i),name(n),department(d),next(NULL){}
};
class CircularLinkedList{
	private:
		Node *head;

	public:
		CircularLinkedList(){
		head=NULL;
		}
		// For Inserting At Start Of Linked List
		void prepend(string id,string name,string depart){
			Node *newNode= new Node(id,name,depart);
			if(head==NULL){
				head=newNode;
				newNode->next=head;
			}
			else{
			
			newNode->next = head;
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            head = newNode;
        }
		}
			
		// Insert Element at Last
		void append(string id,string name,string depart){
			Node *newNode= new Node(id,name,depart);
			if(head==NULL){
				head=newNode;
				newNode->next=head;
			}
			else{
				Node *temp=head;
				while(temp->next!=head){
					temp=temp->next;
				}
				temp->next=newNode;
				newNode->next=head;
			}
		}
		
		// Update Node At Given Index
		void updateNode(string id,string name,string depart,int ind){
			Node *newNode = new Node(id, name, depart);
			int count=1;
			Node *temp=head;
			while(count<ind && temp->next!=head){
				temp=temp->next;
				count++;
			}
	    newNode->next=temp->next->next;
	    temp->next=newNode;
			
		}
		// Update Node At Given Index
		void insertNodeAfter(string id,string name,string depart,int ind){
			Node *newNode = new Node(id,name,depart);
			int count=1;
			Node *temp=head;
			while(count<ind && temp->next!=head){
				temp=temp->next;
				count++;
			}
			Node *prev=temp;
			Node* target=temp->next;
			Node *after=target->next;
			newNode->next=after;
			target->next=newNode;
			
			
		}
		// remove a specific node
		void remove(int index){
			Node *tmph;
			if(index==0){
				head=head->next;
			}
			else{
				int count=1;
				Node *temp=head;
				Node *target;
				while(count<index && temp->next!=head){
					temp=temp->next;
					count++;
				}
			target=temp->next;
            temp->next=temp->next->next;
            delete target;
            
			}
		}
		void mergeList(CircularLinkedList &l1, CircularLinkedList &l2) {
    
    Node *temp1 = l1.head;
    Node *temp2 = l2.head;
    
    head=temp1;

    while (temp1->next != l1.head) {
        temp1 = temp1->next;
    }

    while (temp2->next != l2.head) {
        temp2 = temp2->next;
    }

    temp1->next = l2.head;
    temp2->next = l1.head;

   
}

		void printData(){
			Node *temp=head;
			while(temp->next!=head){
				cout<<"ID: "<<temp->id;
				cout<<" , Name: "<<temp->name;
				cout<<" , Department: "<<temp->department<<"\n";
				temp=temp->next;
			}
		        cout<<"ID: "<<temp->id;
				cout<<" , Name: "<<temp->name;
				cout<<" , Department: "<<temp->department<<"\n";

		}
		
		
};
int main(){
	CircularLinkedList PERM;
	CircularLinkedList CONTRACT;
	CircularLinkedList EMPLOYEE_DB;
	
	PERM.append("101","John Wick","HR");
	PERM.append("102","Tony Stark","Finance");
	PERM.append("103","Peter Parker","Finance");
	cout<<"\nBefore Merging 'PERM' Employees List: \n\n";
    PERM.printData();
    CONTRACT.append("201","Thor","Sales");
	CONTRACT.append("202","Hawkeye","HR");
	CONTRACT.append("203","Wanda maximoff","Marketing");
	cout<<"\n\nBefore Merging 'CONTRACT' Employees List: \n\n";
	CONTRACT.printData();
	
	cout<<"\nAfter Merging 'PERM' & 'CONTRACT' Employees List To 'EMPLOYEE_DB' LIST: \n\n";
	EMPLOYEE_DB.mergeList(PERM,CONTRACT);
	EMPLOYEE_DB.printData();
	
	
}
