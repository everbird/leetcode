/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *pre;

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->pre = NULL;
        preOrder(root);
    }

    void preOrder(TreeNode *node) {
        if (node == NULL) {
            return;
        }

        TreeNode *leftNode = node->left;
        TreeNode *rightNode = node->right;

        if (this->pre != NULL) {
            this->pre->right = node;
        }
        node->left = NULL;
        this->pre = node;

        if (leftNode != NULL) {
            preOrder(leftNode);
        }

        if (rightNode != NULL) {
            preOrder(rightNode);
        }
    }
};
