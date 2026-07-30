class Solution {
public:

    string encode(vector<string>& strs) {
        string deli = ":;";
        string encoded;

        for(string s: strs) {
            encoded.append(s);
            encoded.append(deli);
        }
        cout << encoded;
        return encoded;
    }

    vector<string> decode(string s) {
        string deli = ":;";
        vector<string> decoded;
        if(s.size() == 0) return decoded;

        if(s == deli) {
            decoded.push_back("");
            return decoded;
        };

        string token = "";
        for(int i=0; i < s.size(); i++) {
            
            
            if(s[i] == ':' && s[i+1] == ';') {
                decoded.push_back(token);
                token = "";
                i = i+1;
                continue;
            }
            token.push_back(s[i]);
        }
        return decoded;
    }
};
