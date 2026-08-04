class Solution {
public:
    /*
     - denominations: 1, 2, 5 (e.g.)
     - min_coins[i] -> minimum coins needed to get i amount
     - min_coins[i] = min (1 + min_coins[ i-1 ] , 1 + min_coins[ i-2 ] , 1 + min[ i-5 ]  )
    */

    int coinChange(vector<int>& coins, int amount) {

        // edge base case
        if (amount == 0 ) return 0;

        vector<int> min_coins( amount+1 , -1 );

        // array base case
        min_coins[0] = 0;
        for (int i = 1; i <= amount; i++ ) {

            for (int j = 0; j < coins.size(); j++ ) {

                if ( i == coins[j]) min_coins[i] = 1;

            }

        }

        // computation
        for (int i = 1; i <= amount; i++ ) {
            if ( min_coins[i] == -1) {
                int minn = INT_MAX;
                for (int j = 0; j < coins.size(); j++ ) {
                    if ((i - coins[j] >= 0 && min_coins[i - coins[j]] != -1)) {
                         minn = min( minn, 1 + min_coins[i - coins[j]]);
                    }

                }
                min_coins[i] = minn == INT_MAX ? -1 : minn;
            }
        }

        return min_coins[ amount ];
    }
};
