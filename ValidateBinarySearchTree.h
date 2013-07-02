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
    int pre;
    bool result;

    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->result = true;
        this->pre = -pow(2, 32) + 1;
        this->inOrder(root);
        return this->result;
    }

    void inOrder(TreeNode *node) {
        if (node == NULL) {
            return;
        }

        this->inOrder(node->left);

        if (this->pre >= node->val) {
            this->result = false;
            return;
        }

        this->pre = node->val;

        this->inOrder(node->right);
    }
};
