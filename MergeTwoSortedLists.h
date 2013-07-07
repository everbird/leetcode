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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL;
        ListNode *node = NULL;
        while (l1 != NULL || l2 != NULL) {
            if (head == NULL) {
                if (l1 == NULL) {
                    head = new ListNode(l2->val);
                    l2 = l2->next;
                } else if (l2 == NULL) {
                    head = new ListNode(l1->val);
                    l1 = l1->next;
                } else if (l1->val > l2->val) {
                    head = new ListNode(l2->val);
                    l2 = l2->next;
                } else {
                    head = new ListNode(l1->val);
                    l1 = l1->next;
                }
                node = head;
            } else {
                if (l1 == NULL) {
                    node->next = new ListNode(l2->val);
                    l2 = l2->next;
                } else if (l2 == NULL) {
                    node->next = new ListNode(l1->val);
                    l1 = l1->next;
                } else if (l1->val > l2->val) {
                    node->next = new ListNode(l2->val);
                    l2 = l2->next;
                } else {
                    node->next = new ListNode(l1->val);
                    l1 = l1->next;
                }
                node = node->next;
            }
        }

        return head;
    }
};
