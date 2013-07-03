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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int next_extra = 0;
        bool flag_extra = false;
        ListNode *head = NULL;
        ListNode *node = NULL;

        while (l1 != NULL || l2 != NULL || flag_extra) {
            int l1_value = l1 == NULL? 0: l1->val;
            int l2_value = l2 == NULL? 0: l2->val;
            int sum = l1_value + l2_value + next_extra;
            int value = sum % 10;
            next_extra = sum / 10;
            flag_extra = next_extra != 0;

            if (head == NULL) {
                node = new ListNode(value);
                head = node;
            } else {
                node->next = new ListNode(value);
                node = node->next;
            }

            if (l1 != NULL) {
                l1 = l1->next;
            }

            if (l2 != NULL) {
                l2 = l2->next;
            }
        }

        return head;
    }

};
