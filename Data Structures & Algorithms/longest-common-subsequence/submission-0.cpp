class Solution {

/*

  . c r a b t
. 0 0 0 0 0 0
c 0 1 1 1 1 1
a 0 1 1 2 2 2
t 0 1 1 1 1 3 

*/


/*

  . s t u d e
. 0 0 0 0 0 0
c 0 0 0 0 0 0
a 0 0 0 0 0 0
t 0 0 1 1 1 1
e 0 0 1 1 1 2
*/

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> DP(n + 1, vector<int> (m + 1 , 0));

        for (int i=0; i <= n; i++) {
            for (int j=0; j <= m; j++) {

                if (i == 0 || j == 0) continue;
                else if (text1[ i-1 ] == text2[ j-1 ]) {
                    DP[i][j] = DP[ i-1 ][ j-1 ] + 1;
                } else {
                    DP[i][j] = max(DP[ i-1 ][j] , DP[ i ][ j-1 ]);
                }

            }
        }

        return DP[n][m];
        
    }
};


