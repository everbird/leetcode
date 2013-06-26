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
    bool result;

    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return true;
        }

        this->result=true;
        this->getDepth(root);
        return this->result;
    }

    int getDepth(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }

        int leftValue = this->getDepth(node->left);
        int rightValue = this->getDepth(node->right);

        if (1<abs(leftValue - rightValue)) {
            this->result = false;
        };

        return 1 + (leftValue > rightValue? leftValue: rightValue);
    }
};
