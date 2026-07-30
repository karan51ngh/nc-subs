class Solution {
public:
    int climbStairs(int n) {
        vector<int> stairTable(n,0);

        stairTable[0] = 1; // 1st step
        stairTable[1] = 2; // 2nd step

        for(int i=2; i <n; i++) 
            stairTable[i] = stairTable[i-1] + stairTable[i-2];

        return stairTable[n-1];
    }
};
