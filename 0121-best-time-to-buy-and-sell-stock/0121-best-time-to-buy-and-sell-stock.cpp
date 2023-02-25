class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = INT_MAX;
        int ans = 0;
        for(auto p : prices){
            m = min(m, p);
            ans = max(ans, p-m);
        }
        return ans;
    }
};