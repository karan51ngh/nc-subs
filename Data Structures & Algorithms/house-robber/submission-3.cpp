class Solution {
public:
    /*
        - if we steal from 0 -> i, i is the last house we are at
        - we can or we might not steal money from i
        - money_stolen[ith house] (max money possible at ith house) = 
            nums[i] + money_stolen[ i-2th house ] (steal from i)
            or
            money_stolen[ i-1th house ] (do not steal from i)
    */
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0],nums[1]);

        // vector<int> money_stolen( n );
        
        int prev2 = nums[0];
        int prev1 = max (nums[1], nums[0]);

        for (int i=2; i < n; i++) {
            // money_stolen[i] = max(money_stolen[ i - 2] + nums[i], money_stolen[ i - 1]);
            int temp = prev1;
            prev1 = max (prev1, prev2 + nums[i]);
            prev2 = temp;
        }

        return prev1;
    }
};
