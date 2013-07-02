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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;

        if (root == NULL) {
            return result;
        }

        vector<int> first;
        first.push_back(root->val);
        result.push_back(first);

        vector<TreeNode*> queue;
        queue.push_back(root);
        bool flag = false;

        while (queue.size() > 0) {
            vector<TreeNode*> next_line;
            for (int i=0; i<queue.size(); i++) {
                TreeNode *node = queue.at(i);

                if (node->left != NULL) {
                    next_line.push_back(node->left);
                }

                if (node->right != NULL) {
                    next_line.push_back(node->right);
                }
            }

            queue = next_line;
            if (queue.size() > 0) {
                vector<int> t;
                if (flag) {
                    for (int j=0; j<queue.size(); j++) {
                        t.push_back(queue.at(j)->val);
                    }

                } else {
                    for (int j=queue.size() - 1; j>=0; j--) {
                        t.push_back(queue.at(j)->val);
                    }
                }
                result.push_back(t);
            }

            flag = !flag;

        }

        return result;
    }
};
