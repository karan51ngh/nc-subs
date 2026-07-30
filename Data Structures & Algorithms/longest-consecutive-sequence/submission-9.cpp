class Solution {
public:

    int longestConsecutive(vector<int>& nums) {

        if (nums.size() == 0) return 0;

        unordered_map<int,bool> is_present;

        for (auto n: nums) {
            is_present[n] = true;
        }
        
        int larseq = 1;
        for (auto n: nums) {
            if (is_present[n - 1] == false && is_present[n] == true && is_present[n + 1] == true) {

                int ctr = 0;
                int x = n;
                while(is_present[x]) {
                    ctr++;
                    x++;
                }
                larseq = max(ctr , larseq);
            }
        } 
        return larseq;
    }
};
