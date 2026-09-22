class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> DP(m , vector<int> (n , 0));
        
        DP[m-1][n-1] = 1;
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == (m-1) || j == (n-1)) {
                    DP[i][j] = 1;
                } else {
                    DP[i][j] = DP[i+1][j] + DP[i][j+1];
                }
            }
        }

        return DP[0][0];
        
    }
};
