class Solution {
public:
    map<int, vector<int>> mp;
    long long countPairs(int n, vector<vector<int>>& edges) {
        for(auto x : edges){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        int count = n;
        vector<bool> visited(n, false);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int total = 0;
                dfs(i, total, visited);
                ans += (long long)(count-total)*total;
                count -= total;
            }
        }
        
        return ans;
    }
    void dfs(int node, int &total, vector<bool> &visited){
        visited[node] = true;
        total++;
        for(auto x : mp[node]){
            if(!visited[x]){
                dfs(x, total, visited);
            }
        }
        return;
    }
};