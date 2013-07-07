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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) {
            return NULL;
        }

        if (head->next == NULL) {
            return head;
        }

        ListNode *left = NULL;
        ListNode *right = NULL;

        ListNode *node = head;
        ListNode *newNode = NULL;
        ListNode *leftTail = NULL;
        while (node != NULL) {
            if (node->val < x) {
                if (left == NULL) {
                    left = new ListNode(node->val);
                    newNode = left;
                } else {
                    newNode->next = new ListNode(node->val);
                    newNode = newNode->next;
                }
                leftTail = newNode;
            }
            node = node->next;
        }

        node = head;
        newNode = NULL;
        while (node != NULL) {
            if (node->val >= x) {
                if (right == NULL) {
                    right = new ListNode(node->val);
                    newNode = right;
                } else {
                    newNode->next = new ListNode(node->val);
                    newNode = newNode->next;
                }
            }
            node = node->next;
        }

        if (left == NULL) {
            return right;
        }

        if (leftTail != NULL) {
            leftTail->next = right;
        }

        return left;
    }
};
