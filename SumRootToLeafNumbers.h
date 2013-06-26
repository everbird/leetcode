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

    stack<int> total;
    deque<int> s;

    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        pre_order(root);

        int sum_value = 0;
        int total_count = this->total.size();
        for (int i=0; i<total_count; i++) {
            sum_value += this->total.top();
            this->total.pop();
        }

        return sum_value;
    }

    void pre_order(TreeNode *node) {
        if (node ==  NULL) {
            return;
        }

        this->s.push_front(node->val);

        int _sum = 0;

        if (node->left == NULL && node->right == NULL) {
            for (int i=0; i < this->s.size(); i++) {
                _sum += this->s.at(i) * pow(10, i);
            }
            this->total.push(_sum);
            this->s.pop_front();
            return;
        }

        if (node->left != NULL) {
            pre_order(node->left);
        }

        if (node->right != NULL) {
            pre_order(node->right);
        }

        this->s.pop_front();
    }
};
