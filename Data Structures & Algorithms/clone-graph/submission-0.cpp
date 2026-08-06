/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* actualCloneGraph(Node* node, unordered_map<Node*, Node*> &clonedMap) {

        if (node == nullptr) return node;
        
        if (clonedMap.find(node) != clonedMap.end()) {
            return clonedMap[node];
        }
        
        Node* cloneNode = new Node();
        clonedMap[node] = cloneNode;
        
        vector<Node*> cloneNeighbors;

        for ( auto n: node -> neighbors) {
            cloneNeighbors.push_back( actualCloneGraph(n, clonedMap) );
        }

        cloneNode -> neighbors = cloneNeighbors;
        cloneNode -> val = node -> val;

        
        return cloneNode;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> clonedMap;
        return actualCloneGraph(node, clonedMap);   
    }
};
