class Solution {
public:
    string longestPalindrome(string s) {

        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1,0) );
        int n = s.size();
        int max_len = 1;
        int start_idx = 0;
        if (n == 0) return "";

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                
                if (i == j ) {
                    dp[i][j] = true;
                }
                else if (j - i == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                }

                if (dp[i][j] && (j - i + 1 > max_len)) {
                    max_len = j - i + 1;
                    start_idx = i;
                }
            }
        }

        return s.substr(start_idx, max_len);
    }
};