class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int maxFreq = 0;
        unordered_map<int, int> freqMap;

        for(auto &n: nums) {
            freqMap[n]++;
            maxFreq = max(freqMap[n],maxFreq);
        }
        

        vector<vector<int>> stuff(maxFreq + 1);

        for(auto &pair: freqMap) {
            stuff[pair.second].push_back(pair.first);
        }

        vector<int> sol;
       for (int idx = stuff.size() - 1; idx >= 0; idx--) {

            for (auto n : stuff[idx]) sol.push_back(n);

            if (sol.size() == k) {
                    return sol;
            }
        }

        return sol;
    }
};



/*

1 -> 1
2 -> 2
3 -> 3

*/