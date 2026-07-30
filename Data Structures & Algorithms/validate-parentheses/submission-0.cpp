class Solution {
public:
    bool isValid(string s) {
        vector<char> openPar = {'[', '{', '('};
        vector<char> closePar = {']', '}', ')'};
        unordered_map<char, char> closeOpenMap= {  {']','[' }, {')','(' }, {'}','{' } };
        stack<char> stk;
        for (char c : s) {
            if (find(openPar.begin(), openPar.end(), c) !=openPar.end()) {
                stk.push(c);
            }
            if (find(closePar.begin(), closePar.end(), c) !=closePar.end()){
                if( stk.empty() ) return false;
                if( closeOpenMap[c] != stk.top()) return false;
                else stk.pop();
            }
        }

        if(stk.empty()) return true;
        return false;
    }
};
