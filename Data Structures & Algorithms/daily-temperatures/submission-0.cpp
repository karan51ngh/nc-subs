class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> solution(temperatures.size(), 0);
        stack<int> stk;

        for (int i=0; i < temperatures.size(); i++) {

            if(stk.empty() || temperatures[i] <= temperatures[stk.top()]) {
                stk.push(i);
                cout << "push" << i << endl;
            } else {
                while(temperatures[i] > temperatures[stk.top()]) {
                        solution[stk.top()] = i - stk.top();
                        stk.pop();
                        if(stk.empty()) break;
                }
                stk.push(i);
            }
        }

        // while(!stk.empty()) {
        //     solution[stk.top()] = 0;
        //     stk.pop();
        // }

        return solution;
        
    }
};
