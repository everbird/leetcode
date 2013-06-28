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

    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->result = true;
        this->preOrder(p, q);
        return this->result;
    }

    void preOrder(TreeNode *pNode, TreeNode *qNode) {
        if (pNode == NULL || qNode == NULL) {
            if (pNode != qNode) {
                this->result = false;
            }
            return;
        }

        if (pNode->val != qNode->val) {
            this->result = false;
            return;
        }

        this->preOrder(pNode->left, qNode->left);
        this->preOrder(pNode->right, qNode->right);
    }
};
