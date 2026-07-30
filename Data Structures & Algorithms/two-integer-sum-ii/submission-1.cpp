class Solution {
public:
    /*
        - Window Expand or Contract
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;
        vector<int> solution(2);

        while((nums[ptr1] + nums[ptr2]) != target) {
            if (nums[ptr1] + nums[ptr2] > target) {
                ptr2--;
            } else if (nums[ptr1] + nums[ptr2] < target) {
                ptr1++;
            }
        }

        solution[0] = ptr1 + 1;
        solution[1] = ptr2 + 1;
        return solution;
    }
};
