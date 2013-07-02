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

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        this->index = 0;
        TreeNode *head = this->build(preorder, inorder, 0, 0, preorder.size()-1);
        return head;
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int index, int start, int end) {
        if (start > end) {
            return NULL;
        }

        if (index >= inorder.size()) {
            return NULL;
        }
        this->index = index;
        int value = preorder.at(this->index);
        int pos = this->find(inorder, value);

        TreeNode *node = new TreeNode(value);
        TreeNode *left = this->build(preorder, inorder, this->index+1, start, pos-1);
        TreeNode *right = this->build(preorder, inorder, this->index+1, pos+1, end);
        node->left = left;
        node->right = right;
        return node;
    }

    int find(vector<int> &v, int value) {
        for (int i=0; i<v.size(); i++) {
            if (v.at(i) == value) {
                return i;
            }
        }
        return -1;
    }
};
