class Solution {
public:

    vector<int> calcAnagramMap(string &str) { //O(n)
        vector<int> anagramMapvector (26,0);
        for (char s: str) {
            int index = int(s) - int('a');
            anagramMapvector[index] += 1;
        }
        return anagramMapvector;
    }

    bool isAnagram(vector<int> &anaMap1, vector<int> &anaMap2) {
        if(anaMap1 == anaMap2) {
            return true;
        }
        return false;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> solution;

        unordered_map<string, vector<int>> strAnagramMapMap;

        for(string s: strs) {
            strAnagramMapMap[s] = calcAnagramMap(s);
        }
        
        vector<string> emptyVector;
        emptyVector.push_back(strs[0]);

        solution.push_back(emptyVector);

        bool skipFlag = true;
        for(string str: strs) {
            if(skipFlag) {
                skipFlag = false;
                continue;
            }
            bool flag = false;
            for(auto &vecGrp: solution) {
                if(isAnagram(strAnagramMapMap[str], strAnagramMapMap[vecGrp[0]])) {
                    vecGrp.push_back(str);
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                vector<string> newVector;
                newVector.push_back(str);
                solution.push_back(newVector);
            }
        }

        return solution;
    }
};
