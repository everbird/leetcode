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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) {
            return NULL;
        }

        int length = this->getLength(head);
        while (k >= length) {
            k -= length;
        }

        if (k == 0) {
            return head;
        }

        ListNode *node = head;
        int index = length - k;
        for (int i=0; i<index - 1; i++) {
            node = node->next;
        }

        ListNode *pre = node;

        node = node->next;
        ListNode *newHead = node;

        while (node->next != NULL) {
            node = node->next;
        }

        node->next = head;
        pre->next = NULL;

        return newHead;
    }

    int getLength(ListNode *head) {
        int length = 0;
        ListNode *node = head;
        while (node != NULL) {
            length++;
            node = node->next;
        }
        return length;
    }
};
