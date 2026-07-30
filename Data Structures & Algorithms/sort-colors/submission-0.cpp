class Solution {

/*
    - [ 1 , 0 , 1 , 2 ]
    - [ 0 , 1 , 1 , 2 ]

    - [1 , 2 , 1, 1 , 0 , 2 , 0]

*/
public:
    void sortColors(vector<int>& nums) {

        int count_0 = 0;
        int count_1 = 0;
        int sz = nums.size();

        for (int i = 0; i < sz; i++ ) {
            if (nums[i] == 0) count_0++;
            if (nums[i] == 1) count_1++;
        }

        for (int i = 0; i < sz; i++ ) {
            if (count_0 > 0) {
                nums[i] = 0;
                count_0--;
                continue;
            }

            if (count_1 > 0) {
                nums[i] = 1;
                count_1--;
                continue;
            }

            nums[i] = 2;
        }
    }
};