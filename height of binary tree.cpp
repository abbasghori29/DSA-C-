#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int val): data(val),left(NULL),right(NULL){}
};
class BinaryTree{
	public:
	Node *root;
	BinaryTree(){
		root=NULL;
	}
	void insert(int data){
		root=insertRec(root,data);
	}
	
	void print(){
		inOrderPrint(root);
	}
	int heightOfTree(){
		int height=recHeight(root);
		return height;
	}
	
	private:
		Node *insertRec(Node *node , int data){
		if(node==NULL){
			return new Node(data);
		}
		if(data<node->data){
			node->left=insertRec(node->left,data);
		}
		else{
			node->right=insertRec(node->right,data);
		}
	}
		int recHeight(Node *node){
		if(node==NULL){
			return 0;
		}
		int left=recHeight(node->left);
		int right=recHeight(node->right);
		return max(left,right)+1;
	}
		
	void inOrderPrint(Node *node){
		if(node!=NULL){
			inOrderPrint(node->left);
			cout<<node->data;
			inOrderPrint(node->right);
		}
	}
};
int main(){
	BinaryTree b;
	b.insert(1);
	b.insert(2);
	b.insert(3);
	b.insert(4);
	b.print();
	cout<<"\nHeight Of Tree Is: "<<b.heightOfTree();
}
