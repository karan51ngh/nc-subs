class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int, bool> hasOccured;

        for (auto n : nums) {
            if (hasOccured.find(n) == hasOccured.end()) {
                hasOccured[n] = true;   
            } else { return true; }
        }
        
        return false;
    }
};