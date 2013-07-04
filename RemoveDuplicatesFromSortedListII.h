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
        head = this->removeDupHeaders(head);

        if (head == NULL) {
            return NULL;
        }

        if (head->next == NULL) {
            return head;
        }

        ListNode *node = head;

        while (node != NULL) {

            node->next = this->removeDupHeaders(node->next);
            node = node->next;
        }

        return head;
    }

    ListNode *removeDupHeaders(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        if (head->next == NULL) {
            return head;
        }

        if (head->val != head->next->val) {
            return head;
        }

        ListNode *node = head;

        while (node != NULL) {
            if (node->val == head->val) {
                node = node->next;
            } else {
                return this->removeDupHeaders(node);
            }
        }
        return NULL;
    }
};
