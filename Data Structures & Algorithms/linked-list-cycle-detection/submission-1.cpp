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
    bool hasCycle(ListNode* head) {

        if(!head) return false;

        unordered_map<ListNode*, bool> visited;
        ListNode* node = head;

        while(node->next != nullptr) {
            
            if(visited[node]) return true;

            visited[node] = true;
            node = node -> next;

        }

        return false;
    }
};
