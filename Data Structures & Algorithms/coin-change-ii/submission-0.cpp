class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort( coins.begin(), coins.end() );

        vector<vector<int>> dp(amount  + 1, vector<int> (coins.size() ));

        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {

                if ( i == 0 ) {
                    dp[i][j] = 1;
                    continue;
                }

                int waysWithCoin = ( i >= coins[j]) ? dp[i - coins[j]][j]: 0;
                int waysWithoutCoin = ( j > 0) ? dp[i][j-1]: 0;

                dp[i][j] = waysWithoutCoin + waysWithCoin;
            }
        }


        return dp[amount][coins.size() - 1];
    }
};


