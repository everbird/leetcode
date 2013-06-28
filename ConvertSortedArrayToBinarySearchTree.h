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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() == 0) {
            return NULL;
        }

        return this->buildBST(num, num.size() - 1, 0);
    }

    TreeNode *buildBSTX(vector<int> num, int upper, int lower) {
        if (upper == lower + 1) {
            TreeNode *left = new TreeNode(num.at(lower));
            TreeNode *node = new TreeNode(num.at(upper));
            node->left = left;
            return node;
        }

        if (upper == lower) {
            TreeNode *leaf = new TreeNode(num.at(upper));
            return leaf;
        }

        int mid = (upper + lower) / 2;
        int mid_value = num.at(mid);

        TreeNode *left = mid>=1? this->buildBST(num, mid-1, lower): NULL;
        TreeNode *right = mid+1<num.size()? this->buildBST(num, upper, mid+1): NULL;

        TreeNode *middle = new TreeNode(mid_value);
        middle->left = left;
        middle->right = right;
        return middle;
    }

    TreeNode *buildBST(vector<int> num, int upper, int lower) {
        if (lower > upper) {
            return NULL;
        }

        int mid = lower + (upper - lower) / 2;
        TreeNode *middle = new TreeNode(num.at(mid));
        middle->left = this->buildBST(num, mid-1, lower);
        middle->right = this->buildBST(num, upper, mid+1);
        return middle;
    }

};
