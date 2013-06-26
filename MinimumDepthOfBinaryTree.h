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
    int min_depth;

    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return 0;
        }

        this->min_depth = -1;
        this->preOrder(root, 1);
        return this->min_depth;
    }

    void preOrder(TreeNode *node, int depth) {
        if (node == NULL) {
            return;
        }

        if (node->left == NULL && node->right == NULL) {
            if (this->min_depth == -1 || this->min_depth > depth) {
                this->min_depth = depth;
            }
            return;
        }

        if (node->left != NULL) {
            this->preOrder(node->left, depth+1);
        }

        if (node->right != NULL) {
            this->preOrder(node->right, depth+1);
        }
    }
};
