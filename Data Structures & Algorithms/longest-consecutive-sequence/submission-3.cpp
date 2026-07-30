class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int,bool> number_exists;

        int sz = nums.size();
        if (sz == 0) return 0;

        for (auto n: nums) {
            number_exists[n] = true;
        }

        int longestConsecutiveYet = 1;
        for (int i = 0; i < nums.size(); i++) {
            if(number_exists[nums[i] - 1]) continue;

            int longestconsecutive = 1;
            int j = 1;
            
            while(number_exists[nums[i] + j]){
                longestconsecutive++;
                j++;
            }
            longestConsecutiveYet = max(longestconsecutive,longestConsecutiveYet);
        }
        return longestConsecutiveYet;
    }
};
