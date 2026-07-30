class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mapp;

        for(int i=0; i <nums.size(); i++) {
            if (mapp[nums[i]]) return true;
            mapp[nums[i]] = true;
        }
        
        return false;
    }
};