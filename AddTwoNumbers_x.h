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
        int sum = this->listToNum(l1) + this->listToNum(l2);
        return this->numToList(sum);
    }

    int listToNum(ListNode *head) {
        int scale = 1;
        int r = 0;
        ListNode *node = head;
        while (node != NULL) {
            r = r + node->val*scale;
            node = node->next;
            scale *= 10;
        }
        return r;
    }

    ListNode *numToList(int num) {
        if (num == 0) {
            return new ListNode(0);
        }

        ListNode *head = NULL;
        ListNode *node = NULL;

        while (num != 0) {
            if (head == NULL) {
                head = new ListNode(num % 10);
                node = head;
            } else {
                node->next = new ListNode(num % 10);
                node = node->next;
            }
            num = num / 10;
        }
        return head;
    }
};
