class Solution {
public:
    bool isIndexValid(int i, int j, vector<vector<int>>& grid) {
        if (i < 0) return false;
        if (i >= grid.size()) return false;
        if (j < 0) return false;
        if (j >= grid[0].size()) return false;
        return true;
    }

    void DFS(int i, int j, int& largestArea,  vector<vector<bool>>& visited, vector<vector<int>>& grid, int &areaSoFar, int &color) {

        if (isIndexValid( i , j , grid ) &&  !visited[i][j] && grid[i][j] == color) {
            visited[i][j] = true;
            areaSoFar++;

            DFS( i + 1, j ,largestArea ,visited, grid, areaSoFar, color);
            DFS( i - 1, j ,largestArea ,visited, grid, areaSoFar, color);
            DFS( i , j +1 ,largestArea ,visited, grid, areaSoFar, color);
            DFS( i , j -1 ,largestArea ,visited, grid, areaSoFar, color);

            largestArea = max( areaSoFar , largestArea);
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int largestArea = 0;
        int areaSoFar = 0;
        int color = 0;

        vector<vector<bool>> visited(n, vector<bool>( m, false));

        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    areaSoFar = 0;
                    color = grid[i][j];
                    DFS(i,j,largestArea,visited,grid, areaSoFar, color);
                }
            }
        }
        return largestArea;
    }
};
