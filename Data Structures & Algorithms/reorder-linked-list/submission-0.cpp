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
/*
 - 1 fast and 1 slow. (2x speed)
 - H -> x -> x -> x -> M -> x -> x -> x -> E -> n
 - 2 linked-lists
 - reverse the 2nd list
 - Merge the 2 lists

 - H -> x -> x -> x -> x -> n
*/
    ListNode* merge(ListNode* node1, ListNode* node2) {

        if (node1 == nullptr) return node2;
        if (node2 == nullptr) return node1;

        node1 -> next = merge( node2, node1 -> next);

        return node1;

    }

    ListNode* reverseLL(ListNode* head) {

        if (head == nullptr || head -> next ==nullptr) return head;

        ListNode* temp;
        temp = reverseLL( head -> next );
        
        head -> next -> next = head;
        head -> next = nullptr;

        return temp;
    }

    void reorderList(ListNode* head) {

        // find mid
        if (head -> next == nullptr) return;
        if (head -> next -> next == nullptr) {
            return;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast -> next != nullptr && fast -> next -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        if (fast -> next != nullptr) {
            fast = fast -> next;
            slow = slow -> next;
        }

        // use mid to create 2 linked lists

        ListNode* head2 = slow -> next;
        slow -> next = nullptr;

        // reverse head2

        head2 = reverseLL(head2);


        // merge head1 and head2

        head = merge( head, head2);

    }
};
