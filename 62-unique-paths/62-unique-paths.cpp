class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m, vector<int> (n, -1));
        return pathCounter(dp, 0, 0);
    }
    int pathCounter(vector<vector<int>> &dp, int x, int y){
        if(x >= dp.size() || y >= dp[0].size()) return 0;
        if(x == dp.size()-1 && y == dp[0].size()-1) return 1;
        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = pathCounter(dp, x + 1, y) + pathCounter(dp, x, y + 1);
    }
};