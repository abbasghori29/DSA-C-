#include <iostream>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countValidBSTSubtrees(TreeNode* root, int& count, int min_val, int max_val) {
    if (root == NULL) {
        return 1;
    }

    if (root->val > min_val && root->val < max_val) {
        countValidBSTSubtrees(root->left, count, min_val, root->val);
        countValidBSTSubtrees(root->right, count, root->val, max_val);
            count++;
            return 1;
        
    }

    return 0;
}

int countValidBSTSubtreesInTree(TreeNode* root) {
    int count = 0;
    countValidBSTSubtrees(root, count, INT_MIN, INT_MAX);
    return count;
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);

    int count = countValidBSTSubtreesInTree(root);
    cout << "Number of valid BST subtrees: " << count;


    return 0;
}

