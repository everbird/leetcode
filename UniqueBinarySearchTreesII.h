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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<TreeNode *> r;
        if (n == 0) {
            r.push_back(NULL);
            return r;
        }

        for (int i=0; i<n; i++) {
            vector<TreeNode *> _r = this->makeTrees(i, 0, n-1);
            for (int j=0; j<_r.size(); j++) {
                r.push_back(_r[j]);
            }
        }

        return r;
    }

    vector<TreeNode *> makeTrees(int root, int start, int end) {
        vector<TreeNode *> r;
        if (start > end) {
            return r;
        }

        if (start == end) {
            TreeNode *a = new TreeNode(root+1);
            r.push_back(a);
            return r;
        }

        vector<TreeNode *> leftResult;
        vector<TreeNode *> rightResult;

        for (int i=start; i<root; i++) {
            vector<TreeNode *> leftTrees = this->makeTrees(i, start, root - 1);
            for (int m=0; m<leftTrees.size(); m++) {
                TreeNode *leftHead = leftTrees[m];
                TreeNode *newLeftHead = new TreeNode(root+1);
                newLeftHead->left = leftHead;
                leftResult.push_back(newLeftHead);
            }
        }

        for (int j=root+1; j<=end; j++) {
            vector<TreeNode *> rightTrees = this->makeTrees(j, root + 1, end);
            for (int n=0; n<rightTrees.size(); n++) {
                TreeNode *rightHead = rightTrees[n];
                TreeNode *newRightHead = new TreeNode(root+1);
                newRightHead->right = rightHead;
                rightResult.push_back(newRightHead);
            }

        }

        if (leftResult.size() == 0) {
            return rightResult;
        }

        if (rightResult.size() == 0) {
            return leftResult;
        }

        for (int p=0; p<leftResult.size(); p++) {
            for (int q=0; q<rightResult.size(); q++) {
                TreeNode *lHead = leftResult[p];
                TreeNode *rHead = rightResult[q];
                TreeNode *head = new TreeNode(lHead->val);
                head->left = lHead->left;
                head->right = rHead->right;
                r.push_back(head);
            }
        }

        return r;
    }
};
