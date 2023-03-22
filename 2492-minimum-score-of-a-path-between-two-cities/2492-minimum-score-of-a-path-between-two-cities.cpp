class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        int ans = INT_MAX;
        map<int, vector<pair<int, int>>> mp;
        
        for(int i = 0; i < roads.size(); i++){
            mp[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            mp[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        queue<int> q;
        q.push(n);
        vector<bool> visited(n, false);
        visited[n-1] = true;
        
        while(!q.empty()){
            int tp = q.front();
            q.pop();
            for(auto x : mp[tp]){
                if(!visited[x.first-1]){
                    visited[x.first-1] = true;
                    q.push(x.first);
                }
                ans = min(ans, x.second);
            }
        }
        
        return ans;
    }
};