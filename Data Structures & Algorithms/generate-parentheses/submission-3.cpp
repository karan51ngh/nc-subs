class Solution {
public:
    bool validParenthesis(string str) {
        stack<char> stk;
        for (char s: str) {
            
            if(s == '(') {
                stk.push('(');
            }
            else {
                if (stk.size() == 0) return false;
                stk.pop();
            }
        }
        cout << "loop done" << endl;
        if (stk.size() == 0) return true;
        return false;
    }

    vector<string> generateP(int n) {
        vector<string> solutions;

        if ( n == 1) {
            vector<string> pv = {"()", ")("};
            return pv;
        }
        else {
            vector<string> solution;
            vector<string> recurs = generateP(n-1);

            for ( string recur: recurs) {
                if(find(solution.begin(),solution.end(), "()" + recur) 
                        == solution.end()) {
                    solution.push_back("()" + recur);
                }

                if(find(solution.begin(),solution.end(), ")(" + recur) 
                        == solution.end()) {
                    solution.push_back(")(" + recur);
                }

                if(find(solution.begin(),solution.end(), "(" + recur + ")")
                        == solution.end()) {
                    solution. push_back("(" + recur + ")");
                }

                if(find(solution.begin(),solution.end(), ")" + recur + "(")
                        == solution.end()) {
                    solution. push_back(")" + recur + "(");
                }

                if(find(solution.begin(),solution.end(), recur + "()") 
                        == solution.end()) {
                    solution.push_back(recur + "()");
                }

                if(find(solution.begin(),solution.end(), recur + ")(") 
                        == solution.end()) {
                    solution.push_back(recur + ")(");
                }
            }
            return solution;
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> solution;
        vector<string> recurs = generateP(n);

        for ( string recur: recurs) {
            cout << recur << endl;
            if (validParenthesis(recur))
                solution.push_back(recur);
        }
        return solution;
    }
};
