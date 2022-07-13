class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int wstart = 0;
        int maxProfit = 0;
        
        for(int wend = 0; wend < prices.size(); wend++){
            if(prices[wend] > prices[wstart]) maxProfit = max(maxProfit, prices[wend] - prices[wstart]);
                else wstart = wend;
        }
        return maxProfit;
    }
};