class Solution {
public:
    vector<vector<vector<long>>> dp;
    int mod = 1000000007;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp = vector<vector<vector<long>>> (m, vector<vector<long>>(n, vector<long> (maxMove+1, -1)));
        return helper(startRow, startColumn, maxMove, m, n) % mod;
    }
    int helper(int i, int j, int maxMove, int m, int n){
        if(i < 0 || j < 0 || i == m || j == n) return 1;
        if(maxMove == 0) return 0;
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove] % mod;
        
        long count = 0;
        
        count += (helper(i+1, j, maxMove-1, m, n) % mod);
        count += (helper(i-1, j, maxMove-1, m, n) % mod);
        count += (helper(i, j+1, maxMove-1, m, n) % mod);
        count += (helper(i, j-1, maxMove-1, m, n) % mod);
        
        dp[i][j][maxMove] = count % mod;
        
        return dp[i][j][maxMove];
    }
};