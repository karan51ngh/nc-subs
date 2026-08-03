class Solution {
public:
    /*
     - intution: was house-0 included? Yes/No
    */
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]); 
        if(n == 3) return max(nums[0], max(nums[1], nums[2])); 
        
        vector<int> rob0( n );
        vector<int> rob1( n );

        rob0[0] = nums[0];
        rob0[1] = nums[0];
        rob0[2] = nums[0] + nums[2];

        rob1[0] = 0;
        rob1[1] = nums[1];
        rob1[2] = max(nums[1], nums[2]);

        for (int i = 3; i < n - 1; i++) {
            rob0[i] = max(rob0[ i-2 ] + nums[i], rob0[i-1]);
        }

        for (int i = 3; i < n; i++) {
            rob1[i] = max(rob1[ i-2 ] + nums[i], rob1[i-1]);
        }

        return max(rob0[n-2], rob1[n-1]);
    }
};
