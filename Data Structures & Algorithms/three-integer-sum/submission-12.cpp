class Solution {
public:
    /*
        - [-1,0,1,2,-1,-4]
        - [-4,-1,-1,0,1,2]

    */

    vector<vector<int>> twoSum( vector<int>& nums, int B, int A) {
        int target = -nums[A];
        int C = nums.size() - 1;
        vector<vector<int>> solz;

        while (B < C) {
            if(nums[B] + nums[C] < target) {
                B++;
            } else if (nums[B] + nums[C] > target){
                C--;

            } else {
                vector<int> hehe = {nums[A], nums[B], nums[C]};
                solz.push_back(hehe);
                
                B++;
                C--;

                while (B < C && nums[B] == nums[B - 1]) {
                    B++;
                }
                while (B < C && nums[C] == nums[C + 1]) {
                    C--;
                }
            }
        }

        return solz;

    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if(i !=0 && (nums[i] == nums[i-1])) continue;

            int A = i;
            vector<vector<int>> twoSumSolz = twoSum(nums, A+1, A);
            sol.insert(sol.end(), twoSumSolz.begin(), twoSumSolz.end());

        }

        return sol;

    }
};
