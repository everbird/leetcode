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
    int max_sum;

    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->max_sum = -pow(2, 31);
        this->findLongestPath(root);
        return this->max_sum;
    }

    int findLongestPath(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }

        int max_value = node->val;
        int left_value = this->findLongestPath(node->left);
        int right_value = this->findLongestPath(node->right);

        int max_sum_start_here = node->val;
        if (node->val + right_value > max_sum_start_here) {
            max_sum_start_here = node->val + right_value;
        }
        if (node->val + left_value > max_sum_start_here) {
            max_sum_start_here = node->val + left_value;
        }
        if (node->val + left_value + right_value > max_sum_start_here) {
            max_sum_start_here = node->val + left_value + right_value;
        }

        if (max_sum_start_here > this->max_sum) {
            this->max_sum = max_sum_start_here;
        }

        if (left_value + node->val > max_value) {
            max_value = left_value + node->val;
        }
        if (right_value + node->val > max_value) {
            max_value = right_value + node->val;
        }

        return max_value;
    }
};
