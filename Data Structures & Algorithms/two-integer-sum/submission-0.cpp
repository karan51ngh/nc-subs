class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        unordered_set<int> set;
        unordered_map<int,int> map;
        for(int i=0; i < nums.size(); i++) {
            int antiTarget = target - nums[i]; 
            if(set.count(antiTarget)) {
                solution.push_back(map[antiTarget]);
                solution.push_back(i);
                return solution;
            } else {
                set.insert(nums[i]);
                map[nums[i]] = i;
            }
        }
        return solution;
    }
};
