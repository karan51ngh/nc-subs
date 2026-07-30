class Solution {
public:
    int search(vector<int>& nums, int target) {
        int li = 0;
        int ri = nums.size() - 1;

        while (li <= ri) {
            int idx = (li + ri) / 2;
            if (nums[idx] == target) return idx;
            else if ( target > nums[idx]) li = idx + 1;
            else ri = idx - 1;
        }

        return -1;
    }
};
