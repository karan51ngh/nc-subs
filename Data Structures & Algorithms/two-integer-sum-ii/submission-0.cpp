class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> soln;

        int lp = 0;
        int rp = numbers.size() - 1;

        while(numbers[lp] + numbers[rp] != target) {
            if(numbers[lp] + numbers[rp] >= target) {
                rp--;
            } else if(numbers[lp] + numbers[rp] <= target) {
                lp++;
            }
        }

        soln.push_back(lp+1);
        soln.push_back(rp+1);

        return soln;
    }
};
