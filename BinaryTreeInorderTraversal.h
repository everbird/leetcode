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
    vector<int> data;

    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->data.clear();
        this->InOrder(root);
        return this->data;
    }

    void InOrder(TreeNode *node) {
        if (node ==NULL) {
            return;
        }

        this->InOrder(node->left);
        this->data.push_back(node->val);
        this->InOrder(node->right);
    }
};
