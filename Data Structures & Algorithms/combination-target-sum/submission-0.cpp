class Solution {
public:

    void backtrack(vector<int>& nums, int i, int t, vector<int> &c, vector<vector<int>> &r) {
        if (t == 0) {
            r.push_back(c);
            return;
        }

        if (t < 0 || i >= nums.size()) {
            return;
        }

        c.push_back(nums[i]);
        backtrack(nums, i, t - nums[i], c, r);

        c.pop_back();
        backtrack(nums, i+1, t, c, r);
        

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> result;
        vector<int> current;
        
        backtrack(nums, 0, target, current, result);
        
        return result;
        
    }
};
