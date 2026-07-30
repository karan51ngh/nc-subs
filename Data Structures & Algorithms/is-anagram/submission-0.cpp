class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;

        if(s.size() != t.size()) return false;

        for( char c: s) {
            map[c] += 1;
        }

        for( char c: t) {
            map[c] -= 1;
        }

        for( auto i: map) {
            if(i.second != 0) return false;
        }
        return true;
    }
};
