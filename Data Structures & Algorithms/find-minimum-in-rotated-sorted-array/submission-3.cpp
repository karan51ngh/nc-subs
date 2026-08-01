class Solution {
public:
/*
 1, 3, 4, 6, 8, 9


 6, 8, 9, 1, 3, 4,


 4, 6, 8, 9, 1, 3,


3, 1, 2

2, 1

*/
    int findMin(vector<int> &nums) {

        int p1 = 0;
        int p2 = nums.size() - 1;
        int m;
        while(p1 <= p2) {
            if (nums[p1] <= nums[p2]) {
                return nums[p1];
            } else {
                m = (p1 + p2) / 2;

                if (nums[m] >= nums[p1]) {
                    p1 = m+1;
                } else {
                    p2 = m;
                }
            }
        }

        return nums[m];
        
    }
};
