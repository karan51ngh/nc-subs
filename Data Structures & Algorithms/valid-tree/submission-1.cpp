class Solution {
public:
    bool hasCycle(int node, int parent, vector<vector<int>> &adjmtx, vector<bool> &visited) {
        
        visited[node] = true;
        for (auto n: adjmtx[node]) {
            if (n == parent) continue;
            if (visited[n]) return true;
            if (hasCycle(n, node, adjmtx, visited)) return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        vector<bool> visited(n, false);
        vector<vector<int>> adjmtx(n);

        for (int i = 0; i < edges.size(); i++) {

            adjmtx[edges[i][0]].push_back(edges[i][1]);
            adjmtx[edges[i][1]].push_back(edges[i][0]);
        
        }

        bool potential_sol = hasCycle(0,-1,adjmtx,visited);


        for (auto n: visited) {
            if (n == false) return false;
        }

        return !potential_sol;

    }
};
