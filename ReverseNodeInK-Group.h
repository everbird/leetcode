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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (head == NULL ||head->next == NULL || k <=1) {
            return head;
        }

        // Get the length
        int length = 0;
        ListNode *node = head;
        while (node != NULL) {
            node = node->next;
            length++;
        }

        if (length < k) {
            return head;
        }

        int count = k;
        node = head;
        ListNode *tail = NULL;
        ListNode *pre = NULL;
        while (count>0) {
            ListNode *next = node->next;
            node->next = pre;
            pre = node;
            node = next;
            count --;
        }

        head->next = node;
        tail = head;
        head = pre;
        tail->next = this->reverseKGroup(tail->next, k);
        return head;
    }

};
