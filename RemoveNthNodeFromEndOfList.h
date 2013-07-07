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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *node = head;
        ListNode *nPre = NULL;
        while (node != NULL) {
            if (n > 0) {
                n--;
            } else if (n == 0) {
                nPre = head;
                n--;
            } else {
                nPre = nPre->next;
            }
            node = node->next;
        }

        if (nPre == NULL) {
            head = head->next;
        } else {
            nPre->next = nPre->next->next;
        }

        return head;
    }
};
