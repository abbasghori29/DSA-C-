#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
	 Node* root;
    BinaryTree() {
        root = NULL;
    }

    void insert(int data) {
        root = insertRec(root, data);
    }

    Node* insertRec(Node* node, int data) {
        if (node == NULL) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insertRec(node->left, data);
        }
        else {
            node->right = insertRec(node->right, data);
        }

        return node;
    }

    void inOrder() {
        inOrderRec(root);
    }

    void inOrderRec(Node* node) {
        if (node != NULL) {
            inOrderRec(node->left);
            cout << node->data << " ";
            inOrderRec(node->right);
        }
    }
};
int findMin(Node *root){
	Node *temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp->data;
}
// deletition From BST
Node *deleteFromTree(Node *root,int target){
	if(root==NULL){
		return root;
	}
	if(root->data==target){
		// case:1 (0 child)
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}
       // case:2 (1 child)
//           left child
if(root->left!=NULL && root->right==NULL){
	Node *temp=root->left;
	delete root;
	return temp;
}
//           right child
if(root->left==NULL && root->right!=NULL){
	Node *temp=root->right;
	delete root;
	return temp;
}
      //case:3  (2 child)
      if(root->left!=NULL && root->right!=NULL){
      	int minVal=findMin(root->right);
      	root->data=minVal;
      	root->right = deleteFromTree(root->right,minVal);
      	return root;
	  }
	}
	if(root->data>target){
		root->left=deleteFromTree(root->left,target);
		return root;
	}
	else if(root->data<target){
		root->right=deleteFromTree(root->right,target);
		return root;
	}
	return root;
}
int getheightOfTree(Node *root){
	if(root==NULL){
		return -1;
	}
	int leftHeight=getheightOfTree(root->left);
	int rightHeight=getheightOfTree(root->right);
	return 1+max(leftHeight,rightHeight);
}
int getDepthOfTree(Node *root){
	if(root==NULL){
		return 0;
	}
	int leftDepth=getDepthOfTree(root->left);
	int rightDepth=getDepthOfTree(root->right);
	return 1+max(leftDepth,rightDepth);
}
int getSizeOfTree(Node *root){
	if(root==NULL){
		return 0;
	}
	return 1+getSizeOfTree(root->left)+getSizeOfTree(root->right);
}
int getDiameter(Node *root){
	if(root==NULL){
		return 0;
	}
	int leftDiameter=getDiameter(root->left);
	int rightDiameter=getDiameter(root->right);
	int leftHeight=getheightOfTree(root->left);
	int rightHeight=getheightOfTree(root->right);
	return max(max(leftDiameter,rightDiameter),leftHeight+rightHeight+2);
}
int main() {
    BinaryTree tree;
   tree.insert(1);
   tree.insert(2);
   tree.insert(3);
   tree.insert(4);
   tree.insert(5);
   cout<<"Height Of Tree Is: "<<getheightOfTree(tree.root);
   cout<<"\nDepth Of Tree Is: "<<getDepthOfTree(tree.root);
   cout<<"\nSize Of Tree Is: "<<getSizeOfTree(tree.root);
   cout<<"\nDiameter Of Tree Is: "<<getDiameter(tree.root);




    cout << "\nNodes In Inorder Traversal:\n";
    
//    tree.root=deleteFromTree(tree.root,3);
    tree.inOrder();

    return 0;
}

