class Solution {
public:
    vector<int> topKFrequent(vector<int>&  nums, int k) {

        vector<int> solution;
        unordered_map<int,int> freqMap;
        unordered_map<int,bool> flagMap;
        vector<vector<int>> antiFreqMap(nums.size());

        for(int n: nums) { 
            freqMap[n]+=1;
            flagMap[n]=true;
        }

        for(int n: nums) { 
            if(flagMap[n]) {
                antiFreqMap[freqMap[n] - 1].push_back(n);
                flagMap[n] = false;
            }
        }

        int count = k;

        for (int i = nums.size(); i > 0; i-- ) {
            for ( int j = 0; j < antiFreqMap[i - 1].size(); j++) {
                solution.push_back(antiFreqMap[i - 1][j]);
                count--;

                if(count == 0) break;
            }
            if(count == 0) break;
        }

        return solution;
    }
};
