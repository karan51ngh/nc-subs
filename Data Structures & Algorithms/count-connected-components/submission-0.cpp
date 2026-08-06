class Solution {
public:
    void bfs( int node, int parent, vector<vector<int>> &adjmtx, vector<bool>  &visited) {
        visited[node] = true;
        for (auto n: adjmtx[node]) {
            if (n == parent) continue;
            if (!visited[n]) bfs( n, node, adjmtx, visited);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adjmtx(n);
        vector<bool> visited(n);
        int count = 0;

        for (auto e: edges) {
            adjmtx[e[0]].push_back(e[1]);
            adjmtx[e[1]].push_back(e[0]);
        }

        for (int i=0; i < n; i++) {
            if (!visited[i]) {
                count++;
                bfs( i, -1, adjmtx, visited);
            }
        }
        return count;
    }
};
