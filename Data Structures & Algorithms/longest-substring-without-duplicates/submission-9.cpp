class Solution {
public:

/*


*/


    int lengthOfLongestSubstring(string s) {

    if(s.size() <= 1) return s.size();

        int p1 = 0;
        int p2 = 1;
        int largest = 1;
    
        unordered_map<char,bool> visited_frm_p1;

        visited_frm_p1[ s[p1] ] = true;

        while(p2 < s.size()) {


            if (visited_frm_p1[ s[p2] ]) {

                while(s[p1] != s[p2]) {
                    visited_frm_p1[ s[p1] ] = false;
                    p1++;
                }
                visited_frm_p1[ s[p1] ] = false;
                p1++;

            } else {
                // valid string
                visited_frm_p1[ s[p2] ] = true;
                p2++;

                largest = max(p2 - p1, largest);

            }

        }

        return largest;
        
    }
};
