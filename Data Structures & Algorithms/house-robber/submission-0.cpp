class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0],nums[1]);
        if (n == 3)
            return max(nums[0] + nums[2],nums[1]);

        vector<int> heist(n);

        // heist(n) = nums(n) + max(heist(n-2),heist(n-3))

        heist[0] = nums[0];
        heist[1] = nums[1];
        heist[2] = max(nums[0] + nums[2],nums[1]);

        for(int i = 3; i < n; i++) {
            heist[i] = nums[i] + max(heist[i-2],heist[i-3]);
        }

        return max(heist[n-1], heist[n-2]);
    }
};
