/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
/*
 - approach - 1: 
    - finding size() in first pass
    - finding size() - n in second pass
 - approach - 2 (OPTIMAL): 
    - fastPointer till end
    - slowPointer (constant distance n)
*/
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;

        for (int i = 0; i < n; i++) {
            fastPointer = fastPointer -> next;
        }

        if (fastPointer == nullptr) {
            return head->next;
        }

        while (fastPointer -> next != nullptr) {
            
            fastPointer = fastPointer -> next;
            slowPointer = slowPointer -> next;
        }

        // if (slowPointer == head) {
        //     head  = head -> next;
        //     return head;
        // }

        slowPointer -> next = slowPointer -> next -> next;

        return head;
    }
};
