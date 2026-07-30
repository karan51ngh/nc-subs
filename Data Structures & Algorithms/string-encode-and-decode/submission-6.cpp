class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {

        vector<string> decoded;
        
        int ptr = 0;
        int wrd = 0;

        /*
         - "apple" "is" "fun"
         - "5#apple2#is3#fun"

        */

        while (ptr < s.size()) {
            if(s[ptr] == '#') {
                string num = s.substr(wrd, ptr - wrd);
                int sz = stoi(num);

                string word = s.substr(ptr + 1, sz);
                decoded.push_back(word);

                wrd = ptr + sz + 1;
                ptr = wrd + 1;

            } else {
                ptr++;   
            }
        }

        return decoded;

    }
};
