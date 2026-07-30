class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        int solution = 0;
        for(int x: nums) {
            if(s.find(x-1) == s.end()) {
                
                int seqSize = 0;
                int i = x;
                while(s.find(i) != s.end()) {
                    seqSize++;
                    i++;
                }
                solution = max(solution, seqSize);
            }
        }
        return solution;
    }
};
