#include<iostream>
using namespace std;
struct InnerNode{
	int data;
	InnerNode *next;
	InnerNode(int d):data(d),next(NULL){}
};
struct OuterNode{
	int data;
	InnerNode *innerHead;
	OuterNode *next;
	OuterNode(int d):data(d),next(NULL),innerHead(NULL){}
};
class LinkedList{
	public:
	OuterNode *head;
	LinkedList(){
		head=NULL;
	}
	void insertOuterNode(int data){
		OuterNode *newNode = new OuterNode(data);
		if(head==NULL){
			head=newNode;
		}
		else{
			OuterNode *temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newNode;
		}
	}
void insertInnerNode(int outerData, int innerData) {
    OuterNode *temp = head;
    InnerNode *newNode = new InnerNode(innerData);
    while (temp->data != outerData) {
        temp = temp->next;
    }
    if (temp->innerHead == NULL) {
        temp->innerHead = newNode;
    } else {
        InnerNode *temp2 = temp->innerHead;
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = newNode;
    }
}

	void print(){
		OuterNode *temp1=head;
		while(temp1!=NULL){
			cout<<"\n"<<temp1->data<<" : ";
			if(temp1->innerHead!=NULL){
				InnerNode *temp2=temp1->innerHead;
				while(temp2!=NULL){
					cout<<temp2->data<<" ";
                     temp2=temp2->next;
				}
			}
			temp1=temp1->next;
		}
	}
};
int main(){
	LinkedList l1;
	l1.insertOuterNode(1);
	l1.insertOuterNode(2);
	l1.insertOuterNode(3);
	l1.insertInnerNode(1,4);
	l1.insertInnerNode(1,9);
	l1.insertInnerNode(2,6);
	l1.insertInnerNode(2,8);
	l1.insertInnerNode(3,7);
	l1.insertInnerNode(3,1);
	l1.print();
	
}
