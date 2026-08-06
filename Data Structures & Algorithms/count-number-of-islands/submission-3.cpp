class Solution {
public:
    // int hashIndex (int i, int j) {
    //     return ( i * 1000000 + j * 1000 );
    // }

    void traverse( int i, int j, int &rows, int &cols, 
        vector<vector<bool>> &visited, vector<vector<char>> &grid) {

        if ( visited[i][j] || grid[i][j] == '0') return;

        visited[i][j] = true;

        if ( i+1 < rows && visited[i+1][j] == false && grid[i+1][j] == '1') 
            traverse( i + 1, j, rows, cols, visited, grid);

        if ( j+1 < cols && visited[i][j+1] == false && grid[i][j+1] == '1') 
            traverse( i, j + 1, rows, cols, visited, grid);

        if ( j-1 >= 0 && visited[i][j-1] == false && grid[i][j-1] == '1') 
            traverse( i , j- 1, rows, cols, visited, grid);

        if ( i-1 >= 0 && visited[i-1][j] == false && grid[i -1][j] == '1') 
            traverse( i -1 , j, rows, cols, visited, grid);

        return;
    }


    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // unordered_map <int, bool > visited;
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));

        for (int i=0; i < rows; i++) {
            for (int j=0; j < cols; j++) {
                if (visited[i][j] == false && grid[i][j] == '1') {
                    count++;
                    traverse( i, j, rows, cols, visited, grid);
                }
            }
        }

        return count;

    }
};
