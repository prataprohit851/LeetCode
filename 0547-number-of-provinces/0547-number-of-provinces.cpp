class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                ans++;
                dfs(i, isConnected, visited);
            }
        }
        return ans;
    }
    void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[i] = true;
        for(int j = 0; j < isConnected.size(); j++){
            if(!visited[j] && isConnected[i][j] == 1){
                dfs(j, isConnected, visited);
            }
        }
    }
};