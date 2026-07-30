class Solution {
public:
    int calcHeist(vector<int>& nums, int strtidx) {

        int n = nums.size();
        vector<int> heist(n);

        if(strtidx == 0) {
            heist[0] = nums[0];
            heist[1] = nums[1];

            for (int i = 2; i < n - 1; i++) {
                heist[i] = max(nums[i] + max(heist[i-2], heist[i-3]), heist[i-1]);
            }
            return heist[n-2];
        } else {
            heist[0] = 0;
            heist[1] = nums[1];
            heist[2] = nums[2];

            for (int i = 3; i < n; i++) {
                heist[i] = max(nums[i] + max(heist[i-2], heist[i-3]), heist[i-1]);
            }
            return heist[n-1];
        }
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0],nums[1]);
        if (n == 3)
            return max(nums[2],max(nums[0],nums[1]));

        return max(calcHeist(nums,0),calcHeist(nums,1));     
    }
};
