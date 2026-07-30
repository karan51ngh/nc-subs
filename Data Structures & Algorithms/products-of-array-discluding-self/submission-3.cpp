class Solution {
public:

/*

    [1, 2, 4, 6]

    - L -> R
        [1, 2, 68, 48]

    - R -> L
        [24, 48, 24, 6]


*/
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol(nums.size());
        vector<int> l2r(nums.size());
        vector<int> r2l(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            
            if( i == 0) {
                l2r[i] = nums[i];
                continue;
            }

            l2r[i] = l2r[i - 1] * nums[i];
        }

        for (int i = nums.size() - 1; i >=0; i--) {
            
            if( i == nums.size() - 1) {
                r2l[i] = nums[i];
                continue;
            }

            r2l[i] = r2l[i + 1] * nums[i];
        }

        for (int i =0; i < nums.size(); i++) {
            sol[i] = 1;
            sol[i] = (i > 0) ? sol[i] * l2r[i-1]: sol[i];
            sol[i] = (i < nums.size() - 1) ? sol[i] * r2l[i+1]: sol[i];
        }

        return sol;
    }
};
