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
    TreeNode *p;
    TreeNode *q;
    TreeNode *pre;

    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->pre = NULL;
        this->p = NULL;
        this->q = NULL;
        this->inOrder(root);
        int t = this->p->val;
        this->p->val = this->q->val;
        this->q->val = t;
    }

    void inOrder(TreeNode *node) {
        if (node == NULL) {
            return;
        }

        this->inOrder(node->left);

        if (this->pre != NULL) {
            if (this->pre->val > node->val) {
                if (this->p == NULL) {
                    this->p = this->pre;

                }
                this->q = node;
            }
        }
        this->pre = node;

        this->inOrder(node->right);

    }
};
