class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> comp_exists_pos;
        vector<int> sol(2);
        for (int i=0; i < nums.size(); i++) {
            
            if(comp_exists_pos.find(target - nums[i]) 
                != comp_exists_pos.end()) {

               sol[0] = comp_exists_pos[target - nums[i]];
               sol[1] = i;

               return sol;
            }

            comp_exists_pos[nums[i]] = i;
        }
        return sol;
    }
};
