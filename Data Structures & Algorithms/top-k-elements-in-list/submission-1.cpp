class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int > numsFreq;
        unordered_map<int, vector<int> > freqToNum;
        vector<int> sol;

        for (auto a : nums ) {
            numsFreq[a]++;
        }

        unordered_map<int, bool > visited;

        for (auto a : nums ) {
            if(!visited[a])
                freqToNum[numsFreq[a]].push_back(a);
            
            visited[a] = true;
        }

        for(int i = nums.size(); i > 0; i--) {
            if(k == 0) break;

            if(freqToNum.find(i) != freqToNum.end()) {
                for(auto x: freqToNum[i]) {
                    sol.push_back(x);
                    k--;
                }
            } 
        }

        return sol;
    }
};
