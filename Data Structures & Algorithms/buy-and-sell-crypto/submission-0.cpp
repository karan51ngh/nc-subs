class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int sz = prices.size();
        int l = 0; 
        int r = 0;
        int maxProfit = 0;
        if(sz == 1) return 0;

        for (int i=1; i < sz; i++) {

            if(prices[i] < prices[l]) {
                l = i;
                r = i;
            } else {
                r = i;
                maxProfit = max( prices[r] - prices[l],maxProfit);
            }
        }

        return maxProfit;
    }
};
