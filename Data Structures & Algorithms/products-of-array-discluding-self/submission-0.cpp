class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();

        vector<int> left(sz);
        vector<int> right(sz);
        vector<int> solution(sz);

        left[0] = 1;
        right[sz-1] = 1;

        for(int i=1; i<sz; i++) {
            left[i] = left[i-1] * nums[i-1];
        }

        for(int i=sz-2; i>=0; i--) {
            right[i] = right[i+1] * nums[i+1];
        }

        solution[0] = right[0];
        solution[sz-1] = left[sz-1];

        for(int i = 1; i < sz-1; i++) solution[i] = left[i]*right[i];
        
        return solution;
    }
};
