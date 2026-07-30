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
public:
    ListNode* actualReverseList(ListNode* head, ListNode* &newHead) {

        if(head == nullptr) return nullptr;

        if (head -> next == nullptr) {
            newHead = head;
            return head;
        }

        ListNode* temp = actualReverseList(head->next, newHead);
        head->next = nullptr;
        temp->next = head;
        return head;
    }


    ListNode* reverseList(ListNode* head) {

        ListNode* newHead = nullptr;
        ListNode* temp = actualReverseList(head, newHead);
        return newHead;
    }
};
