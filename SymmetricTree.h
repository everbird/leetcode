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

    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return true;
        }
        this->result = true;
        this->preOrder(root->left, root->right);
        return this->result;
    }

    void preOrder(TreeNode *lNode, TreeNode *rNode) {
        if (lNode == NULL || rNode == NULL) {
            if (lNode != rNode) {
                this->result = false;
            }
            return;
        }

        if (lNode->val != rNode->val) {
            this->result = false;
            return;
        }

        this->preOrder(lNode->left, rNode->right);
        this->preOrder(lNode->right, rNode->left);
    }
};
