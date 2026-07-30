class Solution {

/*
    ["act","pots","tops","cat","stop","hat"]

    [["act"], ["pots", "tops"]]


    ==================================================
    [["hat"],["act", "cat"],["stop", "pots", "tops"]]


*/
public:

    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;

        int size = s.size();

        for (int i = 0; i < size; i++) {
            smap[s[i]]++;
            tmap[t[i]]++;
        }

        for (int i = 0; i < size; i++) {
            if(smap[s[i]] != tmap[s[i]]) return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupanagrams;

        vector<string> emptyVector;
        groupanagrams.push_back(emptyVector);


        groupanagrams[0].push_back(strs[0]);
        if (strs.size() == 1) return groupanagrams;

        int size = strs.size();
        for (int i = 1; i < size; i++) {
            
            bool existingGroup = false;
            
            for (int j = 0; j < groupanagrams.size(); j++) {
                if (isAnagram(groupanagrams[j][0] , strs[i])) {
                    groupanagrams[j].push_back(strs[i]);
                    existingGroup = true;
                    break;
                }
            }

            if (!existingGroup) {
                vector<string> emptyVector;
                emptyVector.push_back(strs[i]);
                groupanagrams.push_back(emptyVector);
            }
        }
        return groupanagrams;
    }
};
