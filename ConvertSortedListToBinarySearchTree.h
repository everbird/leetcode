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
        int length = this->getListLength(head);
        return this->buildBST(head, 0, length - 1);
    }

    TreeNode *buildBST(ListNode *&list, int start, int end) {
        if (start > end) {
            return NULL;
        }

        int mid = start + (end - start) / 2;
        TreeNode *left = this->buildBST(list, start, mid-1);

        TreeNode *parent = new TreeNode(list->val);
        parent->left = left;
        list = list->next;

        parent->right = this->buildBST(list, mid+1, end);
        return parent;
    }

    int getListLength(ListNode *head) {
        int length = 0;
        ListNode *node = head;
        while (node != NULL) {
            node = node->next;
            ++length;
        }
        return length;
    }
};
