class Solution {
public:


    int maxFreq(unordered_map<char,int> &freqMap) {
        int maxf = 0;
        for(auto &pair: freqMap) {
            maxf = max(maxf , pair.second);
        }
        return maxf;

    }

    int characterReplacement(string s, int k) {

        int sz = s.size();
        if (sz <= 1) return sz;

        unordered_map<char,int> freqMap;
        int p1 = 0;
        int p2 = 1;
        int maxs = 1;
        

        freqMap[ s[p1] ]++;

        while (p2 < sz) {
            freqMap[ s[p2] ]++;
            int length = p2 - p1 + 1;

            if( length - maxFreq(freqMap) <= k ) {
                maxs = max(maxs , length);
            } else {
                freqMap[ s[p1] ]--;
                p1++;
            }
            p2++;
        }

        return maxs;
        
    }
};
