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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (lists.size() == 0) {
            return NULL;
        }

        ListNode *newHead = NULL;
        ListNode *node = NULL;
        int length = 0;

        ListNode *minNode = this->findMinNode(lists);

        while (minNode != NULL) {
            if (newHead == NULL) {
                node = minNode;
                newHead = node;
            } else {
                node->next = minNode;
                node = node->next;
            }
            minNode = this->findMinNode(lists);
        }

        return newHead;
    }

    ListNode *findMinNode(vector<ListNode *> &lists) {
        ListNode *minNode = NULL;
        int index = 0;
        for (int i=0; i<lists.size(); i++) {
            if (minNode == NULL) {
                minNode = lists[i];
                index = i;
            } else {
                ListNode *thisNode = lists[i];
                if (thisNode != NULL &&minNode->val > thisNode->val) {
                    minNode = thisNode;
                    index = i;
                }
            }
        }
        lists[index] = minNode != NULL? minNode->next: NULL;
        return minNode;
    }
};
