class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int sz = s.size();
        unordered_map<char, bool> visited;

        if(sz <= 1) return sz;
        int longest = 1;
        int l = 0;
        // int r = 1;
        visited[s[0]] = true;

        for (int i = 1; i < sz; i++) {
            if(visited[s[i]]) {
                visited[s[l]] = false;
                l = l+1;
                i = i-1;
            } else {
                visited[s[i]] = true;
                longest = max(i - l + 1, longest);
            }
        }
        return longest;
    }
};
