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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *node = head;
        if (node == NULL) {
            return NULL;
        }
        if (node->next == NULL) {
            return node;
        }

        head = node->next;
        ListNode *tail = node;
        while (node != NULL && node->next != NULL) {
            tail->next = node->next;
            this->swap(node, node->next);
            tail = node;
            node = node->next;
        }

        return head;
    }

    void swap(ListNode *first, ListNode *second) {
        ListNode *next = second->next;
        second->next = first;
        first->next = next;
    }
};
