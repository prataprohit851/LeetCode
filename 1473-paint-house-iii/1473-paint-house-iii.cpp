class Solution {
public:
    int INF = 1000001;
    vector<vector<vector<int>>> dp;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int t) {
        dp = vector<vector<vector<int>>> (m, vector<vector<int>>(t+1, vector<int>(n+1, -1)));
        int ans = dfs(houses, cost, m, n, t, 0, 0, 0);
        return (ans < INF) ? ans : -1;
    }
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int i, int nbr, int left){
        
        if(i == m){
            return (nbr == target) ? 0 : INF;
        }
        
        if(nbr > target) return INF;
        
        if(dp[i][nbr][left] != -1) return dp[i][nbr][left];
        
        if(houses[i] == 0){ // TO BE PAINTED
            int minCost = INF;
            for(int x = 1; x <= n; x++){
                int newNbr = nbr;
                if(x != left) newNbr++;
                minCost = min(minCost, cost[i][x-1] + dfs(houses, cost, m, n, target, i+1, newNbr, x));
            }
            dp[i][nbr][left] = minCost;
            return dp[i][nbr][left];
        }
        else{ // ALREADY PAINTED
            int newNbr = nbr;
            if(houses[i] != left) newNbr++;
            dp[i][nbr][left] = dfs(houses, cost, m, n, target, i+1, newNbr, houses[i]);
            return dp[i][nbr][left];
        }
    }
};