class Solution {
public:
    bool isOpenP(char p) {
        vector<char> openP = { '(' , '{' , '[' };
        return find(openP.begin() , openP.end(), p) != openP.end();
    }

    bool isMatchP(char p1, char p2) {
        if (p1 == '{' and p2 == '}') return true;
        if (p1 == '(' and p2 == ')') return true;
        if (p1 == '[' and p2 == ']') return true;
        return false;
    }


    bool isValid(string s) {
        stack<int> st;

        for(auto &c:s ) {
            if (isOpenP(c)) {
                st.push(c);
            } else {
                if (st.empty()) return false;
                if (isMatchP( st.top() , c )) {
                    
                    st.pop();
                    continue;

                } else {
                    return false;
                }

            }
        }

        return st.empty();
    }
};
