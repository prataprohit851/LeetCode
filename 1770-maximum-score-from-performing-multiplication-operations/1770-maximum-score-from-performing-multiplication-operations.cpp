class Solution {
public:
    vector<vector<int>> dp;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        dp.assign(m+1,vector<int>(m+1,INT_MIN));
        return helper(nums, multipliers, 0, nums.size()-1 ,0);;
    }
    int helper(vector<int>& n, vector<int>& m, int i, int j, int k){
        if(k == m.size()) return 0;
        if(dp[i][k] != INT_MIN) return dp[i][k];
        
        int left = (m[k]*n[i]) + helper(n, m, i+1, j, k+1);
        int right = (m[k]*n[j]) + helper(n, m, i, j-1, k+1);
        
        dp[i][k] = max(left, right);
        return dp[i][k];
    }
    
};