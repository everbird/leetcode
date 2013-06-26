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
    vector<int> s;
    vector<vector<int>> found;

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->found.clear();
        this->s.clear();
        preOrderTraversal(root, sum);
        return this->found;
    }

    void preOrderTraversal(TreeNode *node, int sum) {
        if (node == NULL) {
            return;
        }

        this->s.push_back(node->val);

        if (node->left == NULL && node->right == NULL) {
            int _sum = 0;
            for (int i=0; i<this->s.size(); i++) {
                _sum += this->s.at(i);
            }
            if (_sum == sum) {
                this->found.push_back(this->s);
            }
            this->s.pop_back();
            return;
        }

        if (node->left != NULL) {
            preOrderTraversal(node->left, sum);
        }

        if (node->right != NULL) {
            preOrderTraversal(node->right, sum);
        }

        this->s.pop_back();
    }
};
