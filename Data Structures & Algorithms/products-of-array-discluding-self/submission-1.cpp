class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int sz = nums.size();

        vector<int> l2r(sz);
        vector<int> r2l(sz);
        vector<int> soln(sz);

        for (int i=0; i < sz; i++) {
            if (i == 0) {
                l2r[i] = nums[i];
                continue;
            }
            l2r[i] = l2r[i-1] * nums[i];
        }

        for (int i=sz-1; i >= 0; i--) {
            if (i == sz-1) {
                r2l[i] = nums[i];
                continue;
            }
            r2l[i] = r2l[i+1] * nums[i];
        }

        for (int i=0; i < sz; i++) {
                if (i == 0) {
                    soln[i] = r2l[i+1];
                    continue;
                }

                if (i == sz-1) {
                    soln[i] = l2r[i-1];
                    continue;
                }

                soln[i] = l2r[i-1] * r2l[i+1];
        }

     return soln;
    }
};
