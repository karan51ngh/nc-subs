class Solution {
public:

    string commonPrefix(string &str1, string &str2) {
        string sol;

        int n1 = str1.size();
        int n2 = str2.size();

        int i = 0;

        while(str1[i] == str2[i] && i < min(str1.size(), str2.size()) ) {
            sol.push_back(str1[i]);
            i++;
        }
        return sol;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string sol;

        if(strs.size() == 1) return strs[0];

        sol = commonPrefix(strs[0],strs[1]);

        for(int i = 1; i < strs.size() - 1; i++ ) {
            sol = commonPrefix(sol,strs[i+1]);
        }

        return sol;
    }
};