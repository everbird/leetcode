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
    int index;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->index = 0;
        return this->build(inorder, postorder, 0, 0, inorder.size() - 1);
    }

    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int index, int start, int end) {
        if (start > end) {
            return NULL;
        }

        if (index >= inorder.size()) {
            return NULL;
        }

        this->index = index;
        int value = postorder.back();
        postorder.pop_back();
        int pos = this->find(inorder, value);
        TreeNode *node = new TreeNode(value);
        node->right = this->build(inorder, postorder, this->index+1, pos+1, end);
        node->left = this->build(inorder, postorder, this->index+1, start, pos-1);
        return node;
    }

    int find(vector<int> &v, int value) {
        for (int i=0; i<v.size(); i++) {
            if (value == v.at(i)) {
                return i;
            }
        }

        return -1;
    }
};
