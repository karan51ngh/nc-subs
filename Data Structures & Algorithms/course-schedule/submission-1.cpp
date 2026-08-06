class Solution {
public:
/*
[[1,4],[2,4],[3,1],[3,2]]

4 - 1,2
3 - 1,2


// boils don to finding a loop in the graph.

*/
    bool hasCycle(int node, vector<vector<int>> &adjmtx, vector<int> &states) {
        int numCourses = adjmtx.size();
        if (states[node] == 1) return true;
        if (states[node] == 2) return false;

        states[node] = 1;

        for (auto n: adjmtx[node]) {
            if (hasCycle( n, adjmtx, states)) return true;
        }

        states[node] = 2;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

         vector<vector<int>> adjmtx(numCourses);

         // 0 = Unvisited, 1 = Visiting, 2 = Visited/Safe
        vector<int> states(numCourses, 0);

         for (int i=0; i < prerequisites.size(); i++) {
            adjmtx[prerequisites[i][1]].push_back(prerequisites[i][0]);
         }

         for (int i=0; i < numCourses; i++) {
            if (hasCycle( i, adjmtx, states)) return false;
         }

        return true;
    }
};
