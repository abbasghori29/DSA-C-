#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
	int height;
	Node(int val): data(val),left(NULL),right(NULL),height(1){}
};
class AVL{
	public:
	Node *root;
	AVL(){
		root=NULL;
	}
	 int getHeight(Node* root) {
        if (root == NULL){
             return 0;	
		}
        return root->height;
    }
    int getBalanceFactor(Node* root) {
        if (root == NULL)
            return 0;
        return getHeight(root->left) - getHeight(root->right);
    }
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }
     Node* insert(Node* root, int value) {
        if (root == NULL){
		
            return new Node(value);
        }
        if (value < root->data){
            root->left = insert(root->left, value);
        }
        else if (value > root->data){
            root->right = insert(root->right, value);
        }
        else{
           return root;	
		}
            

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalanceFactor(root);

        // Left Heavy
        if (balance > 1) {
//        	left left case
            if (value < root->left->data) {
                return rotateRight(root);
            } else {
//            	left right case
                root->left = rotateLeft(root->left);
                return rotateRight(root);
            }
        }
        
        // Right Heavy
        if (balance < -1) {
//        	right right case
            if (value > root->right->data) {
                return rotateLeft(root);
            } else {
//            	right left case
                root->right = rotateRight(root->right);
                return rotateLeft(root);
            }
        }

        return root;
    }

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
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalanceFactor(root);

        // Left Heavy
        if (balance > 1) {
//        	left left case
            if (getBalanceFactor(root->left) >= 0) {
                return rotateRight(root);
            } else {
//            	left right case
                root->left = rotateLeft(root->left);
                return rotateRight(root);
            }
        }

        // Right Heavy
        if (balance < -1) {
//        	right right case
            if (getBalanceFactor(root->right) <= 0) {
                return rotateLeft(root);
            } else {
//            	right left case
                root->right = rotateRight(root->right);
                return rotateLeft(root);
            }
        }

	return root;
}
    void inOrder(Node* root) {
        if (root != NULL) {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }
    
void insert(int value) {
        root = insert(root, value);
    }

    void inOrderTraversal() {
        inOrder(root);
        cout << endl;
    }
    };
int main() {
    AVL avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);
    avl.deleteFromTree(avl.root,30);

    cout << "inOrder traversal of AVL tree: ";
    avl.inOrderTraversal();

    return 0;
}

