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

// class Solution {
// public:
//     bool hasCycle(ListNode* head) {

//         unordered_map<ListNode*, bool> visited;

//         ListNode* node = head;
//         while (node != nullptr) {

//             if (visited[node]) return true;
//             visited[node] = true;
//             node = node -> next;

//         }

//         return false;
        
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode* head) {

        if (head == nullptr || head -> next == nullptr) return false;


        unordered_map<ListNode*, bool> visited;

        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        while (fastPointer != nullptr) {

            slowPointer = slowPointer -> next;
            if (fastPointer -> next) {
                fastPointer = fastPointer -> next -> next;
            } else {
                return false;
            }

            if (slowPointer == fastPointer) return true;

        }

        return false;
        
    }
};
