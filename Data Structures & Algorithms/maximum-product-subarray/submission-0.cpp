class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int MAX_SO_FAR = nums[0];
        int MIN_SO_FAR = nums[0];
        int CUR_MAX = nums[0];
        int CUR_MIN = nums[0];


        for (int i=1; i < nums.size(); i++) {

            int mul_curr_max = nums[i] * CUR_MAX;

            int mul_curr_min = nums[i] * CUR_MIN;

            CUR_MAX = max( max( mul_curr_max, mul_curr_min) , nums[i]);
            CUR_MIN = min( min( mul_curr_max, mul_curr_min) , nums[i]);


            MAX_SO_FAR = max( CUR_MAX,MAX_SO_FAR );
            // MIN_SO_FAR = min( CUR_MIN,MIN_SO_FAR);

        }

        return MAX_SO_FAR;

    }
};
