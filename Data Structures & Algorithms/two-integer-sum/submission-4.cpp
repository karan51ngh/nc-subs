class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> twosum;
        unordered_map<int, int> storedIndices;
        int size = nums.size();

        for(int i=0; i < size; i++) {
            storedIndices[nums[i]] = i;
        }

        for(int i=0; i < size; i++) {

            if (storedIndices
                .find(target - nums[i]) != storedIndices.end()) {
                    int j = storedIndices[target - nums[i]];
                    if(i == j) continue;

                    twosum.push_back(i);
                    twosum.push_back(j);
                    
                    return twosum;
                }
        }

        return twosum;
    }
};
