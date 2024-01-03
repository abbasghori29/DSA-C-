#include<iostream>
#include<string>
#include<math.h>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int val):data(val),next(NULL){}
};
class Stack{
	public:
	Node *head;
	Stack(){
		head=NULL;
	}
	void push(int d){
		Node *newNode = new Node(d);
		if(head==NULL){
			head=newNode;
		}
		else{
			newNode->next=head;
			head=newNode;
		}
	}
	int pop(){
		if(head==NULL){
			cout<<"Stack Is Already Empty!";
			return -1;
		}
		else{
			int val=head->data;
			head=head->next;
			return val;
		}
	}
};

int postFixEvalution(string exp){
	Stack s;
	int i;
	for(i=0;i<exp.length();i++){
		if(exp[i]>='0' && exp[i]<='9'){
			s.push(exp[i]-'0');
		}
		else{
			int op1=s.pop();
			int op2=s.pop();
			switch(exp[i]){
				case '+':
					s.push(op1+op2);
					break;
				case '-':
					s.push(op1-op2);
					break;
				case '*':
					s.push(op1*op2);
					break;
				case '/':
					s.push(op1/op2);
					break;
				case '^':
					s.push(pow(op1,op2));
					break;
			}
		}
	}
	return s.pop();
}
int main(){
	string exp="02+52*7+-";
	cout<<postFixEvalution(exp);
	
}

