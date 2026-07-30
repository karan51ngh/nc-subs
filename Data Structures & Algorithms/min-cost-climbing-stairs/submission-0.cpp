class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        vector<int> minCost(sz);

        minCost[0] = 0;
        minCost[1] = 0;

        for(int i = 2; i <sz; i++)
            minCost[i] = min(minCost[i-1] + cost[i-1], minCost[i-2] + cost[i-2]);
        
        return min(minCost[sz-1] + cost[sz-1], minCost[sz-2] + cost[sz-2]);
    }
};
