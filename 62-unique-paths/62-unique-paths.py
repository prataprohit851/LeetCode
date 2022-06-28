class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        return paths(dp, 0, 0);
    }
    int paths(vector<vector<int>>& dp, int i, int j){
        if(i == dp.size()-1 && j == dp[0].size()-1) return 1;
        if(i > dp.size()-1 || j > dp[0].size()-1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = paths(dp, i+1, j) + paths(dp, i, j+1);
        return dp[i][j];
    }
};