class Solution {
public:
    int getNumber(string num) {
        return stoi(num);
    }
    int evalRPN(vector<string>& tokens) {

        int eval;
        stack<int> st;
        vector<string> operands = {"+", "-", "*", "/"};
        
        for(string token: tokens) {

            if(find(operands.begin(), operands.end(), token) != operands.end()) {

                int second = st.top();
                st.pop();

                int first = st.top();
                st.pop();

                if (token == "+") {
                    eval = first + second; 
                } else if (token == "-") {
                    eval = first - second;
                } else if (token == "*") {
                    eval = first * second;
                } else {
                    eval = first / second;
                }
                cout << eval << endl;
                st.push(eval);

            } else {
                // cout << getNumber(token) << endl;
                st.push(getNumber(token));
            }
        }
        return st.top();
    }
};
