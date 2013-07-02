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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head->next == NULL) {
            return head;
        }

        if (m == n) {
            return head;
        }

        ListNode *preTail = NULL;
        if (m > 1) {
            preTail = head;
            for (int i=1; i<m-1; i++) {
                preTail = preTail->next;
            }
        }

        ListNode *mStart = m == 1? head: preTail->next;
        ListNode *mNode = mStart;
        ListNode *nextNode = mNode->next;
        mNode->next = NULL;
        ListNode *t = NULL;

        for (int i=0; i<n-m; i++) {
            t = nextNode->next;
            nextNode->next = mNode;
            mNode = nextNode;
            nextNode = t;
        }
        ListNode *postHead = nextNode;

        if (preTail != NULL) {
            preTail->next = mNode;
        }

        mStart->next = postHead;

        return m!=1? head: mNode;
    }
};
