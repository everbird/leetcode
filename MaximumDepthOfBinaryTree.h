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
    int max_depth;

    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (root == NULL) {
            return 0;
        }

        this->max_depth = -1;
        this->preOrder(root, 1);
        return this->max_depth;
    }

    void preOrder(TreeNode *node, int depth) {
        if (node == NULL) {
            return;
        }

        if (node->left == NULL && node->right == NULL) {
            if (this->max_depth == -1 || this->max_depth < depth) {
                this->max_depth = depth;
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
