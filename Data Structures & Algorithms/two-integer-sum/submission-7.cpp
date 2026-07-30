class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> reverse_index;

        vector<int> solution = {-1, -1};

        for (int i = 0; i < nums.size(); i++) {
            if (reverse_index.contains(target - nums[i])) {
                solution[0] = reverse_index[target - nums[i]];
                solution[1] = i;
            }
            reverse_index[nums[i]] = i;
        }   


        return solution;
    }
};
