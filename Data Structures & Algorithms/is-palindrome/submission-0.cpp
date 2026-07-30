class Solution {
public:

    bool isAlphaNumeric(char c) {

        int asciiNum = (int)c;

        int ascii_a = (int)'a';
        int ascii_z = (int)'z';

        int ascii_A = (int)'A';
        int ascii_Z = (int)'Z';

        int ascii_0 = (int)'0';
        int ascii_9 = (int)'9';

        if(asciiNum >= ascii_a && asciiNum <= ascii_z) return true;
        if(asciiNum >= ascii_A && asciiNum <= ascii_Z) return true;
        if(asciiNum >= ascii_0 && asciiNum <= ascii_9) return true;

        return false;
    }

    string asciiLowerCaseVersion(string s) {
        string apple;

        for (auto c : s) {
            if(isAlphaNumeric(c)) apple += tolower(c);;
        }

        return apple;
    }

    bool isPalindrome(string s) {
        string str = asciiLowerCaseVersion(s);

        int sz = str.size();
        int lp = 0;
        int rp = sz - 1;

        for (int i=0; i <= sz/2; i++) {
            if(str[lp] != str[rp]) return false;
            lp++;
            rp--;
        }

        return true;
    }
};
