class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int max_so_far = 1;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i=1; i < n; i++) {
            int max_untill_i = 0;
            for (int j=0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    max_untill_i = max( dp[j] , max_untill_i );
                }
            }
            dp[i] = 1 + max_untill_i;
            max_so_far = max(dp[i],max_so_far);
        }
        
        return max_so_far;
    }
};
