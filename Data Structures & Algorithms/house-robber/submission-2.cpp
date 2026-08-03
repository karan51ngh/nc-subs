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

        vector<int> money_stolen( n );
        
        money_stolen[0] = nums[0];
        money_stolen[1] = max (nums[1], nums[0]);

        for (int i=2; i < n; i++) {
            money_stolen[i] = max(money_stolen[ i - 2] + nums[i], money_stolen[ i - 1]);
        }

        return money_stolen[ n-1 ];
    }
};
