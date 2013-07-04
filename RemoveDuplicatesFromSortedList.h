/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *pre = NULL;
        ListNode *node = head;

        while (node != NULL) {
            if (pre == NULL) {
                pre = node;
            }
            if (pre->val != node->val) {
                pre->next = node;
                pre = node;
            }
            node = node->next;
        }

        if (pre != NULL) {
            pre->next = NULL;
        }

        return head;
    }
};
