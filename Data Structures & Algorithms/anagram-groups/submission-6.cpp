class Solution {
public:

    bool isAnagram(string &s1, string &s2) {
        unordered_map<char, int> count;

        for (auto s: s1) {
            count[s]++;
        }

        for (auto s: s2) {
            count[s]--;
        }

        for (int i=0; i < 26; i++) {
            if(count[ (char)(int('a') + i) ] 
                != 0
                ) return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> solution;

        for( int i = 0; i < strs.size(); i++ ) {

            bool curr = false;

            for( int j = 0; j < solution.size(); j++ ) {
                
                if(isAnagram( solution[j][0] , strs[i] )) {
                    curr = true;
                    solution[j].push_back(strs[i]);
                }

            }   

            if(curr) continue;

            vector<string> temp = {strs[i]};
            solution.push_back(temp);
        }

        return solution;
    }
};
