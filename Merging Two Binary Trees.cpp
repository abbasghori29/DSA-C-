#include<iostream>
#include<vector>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int val): data(val),left(NULL),right(NULL){}
};
class BST{
	public:
	Node *root;
	BST(){
		root=NULL;
	}
	void insert(int d){
		root=insertRec(root,d);
	}
	Node *insertRec(Node *root,int d){
		if(root==NULL){
			return new Node(d);
		}
		else if(d>root->data){
			root->right=insertRec(root->right,d);
		}
		else{
			root->left=insertRec(root->left,d);
		}
	}
	void inOrder(vector<int> &in){
		inOrderRec(root,in);
	}
	void inOrderRec(Node *root,vector<int> &in){
		if(root==NULL){
			return;
		}
		inOrderRec(root->left,in);
		in.push_back(root->data);
		inOrderRec(root->right,in);
	}
};
vector<int> merge(vector<int> first,vector<int> second){
	int i=0,j=0;
	vector<int> mix;
	while(i<first.size() && j<second.size()){
		if(first[i]<second[j]){
			mix.push_back(first[i]);
			i++;
		}
		else{
			mix.push_back(second[j]);
			j++;
		}
	}
	while(i<first.size()){
		mix.push_back(first[i]);
		i++;
	}
	while(j<second.size()){
		mix.push_back(second[j]);
		j++;
	}
	return mix;
}
void printTree(Node *root){
	if(root == NULL){
		return;
	}
	printTree(root->left);
	cout<<root->data<<" ";
	printTree(root->right);
	
}
int main(){
	BST t1;
	BST t2;
	BST sortedTree;
	vector<int> bt1;
	vector<int> bt2;
	vector<int> sort;
	t1.insert(5);
	t1.insert(3);
	t1.insert(6);
	t1.insert(2);
	t1.insert(4);
	t1.inOrder(bt1);
	t2.insert(2);
	t2.insert(1);
	t2.insert(3);
	t2.insert(7);
	t2.insert(6);
	t2.inOrder(bt2);
	sort=merge(bt1,bt2);
	for(int i=0;i<sort.size();i++){
		sortedTree.insert(sort[i]);
	}
	cout<<"Data Of Tree 1: ";
	printTree(t1.root);
	cout<<"\nData Of Tree 2: ";
	printTree(t2.root);
	cout<<"\nData Of Merged Tree 1 and Tree 2: ";
	printTree(sortedTree.root);
}
