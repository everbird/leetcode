/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<int> num = this->convertListToArray(head);

        if (num.size() == 0) {
            return NULL;
        }

        return this->buildBST(num, num.size() - 1, 0);
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

    vector<int> convertListToArray(ListNode* head) {
        vector<int> array;
        ListNode* node = head;
        while (node != NULL) {
            array.push_back(node->val);
            node = node->next;
        }
        return array;
    }
};
