class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        /*
            - 0 <= nums[i] <= 1000
            - 2 SUBSETS - P and N
            - s(P) + s(N) = s(nums) 
            - s(P) - s(N) = target
            - s(P) = (s(nums) + target)/2
            - find number of ways to make P
        */

        /*
            - [5, 4, 3, 6, 8, 9, 7, 1]
            - 12

                0  1  2  3  4  5  6  7  8  9  10  11  12
            .   1  0  0  0  0  0  0  0  0  0  0  0  0  0 
            5   1  0  0  0  0  1  0  0  0  0  0  0  0  0   
            4   1  0  0  0  1  1  0  0  0  1  0  0  0  0 
            3
            6
            8
            9
            7
            1

        */

        int summ = 0;
        int n = nums.size();
        for (auto x:nums) summ += x;

        int fakeTarget = (summ + target) / 2;

        // EDGE CASES: impossible to reach target
        if (abs(target) > summ || (summ + target) % 2 != 0) {
            return 0;
        }

        vector<vector<int>> DP( fakeTarget+1 , vector<int> ( n+1 ,0));

        DP[0][0] = 1;
        for (int i=0; i<= fakeTarget; i++) {
            for (int j=0; j <= n; j++ ) {
                if ( j == 0 ) continue;
                else if (i >= nums[ j-1 ]) {
                    DP[i][j] = DP[ i - nums[ j-1 ] ][ j-1 ] + DP[ i ][ j-1 ];
                } else {
                    DP[i][j] = DP[ i ][ j-1 ];
                }
            }
        }

        return DP[fakeTarget][n];
    }
};
