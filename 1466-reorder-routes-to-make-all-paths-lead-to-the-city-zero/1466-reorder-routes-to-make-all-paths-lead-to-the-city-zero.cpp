class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        map<int, vector<int>> front;
        map<int, vector<int>> back;
        for(int i = 0; i < c.size(); i++){
            front[c[i][0]].push_back(c[i][1]);
            back[c[i][1]].push_back(c[i][0]);
        }
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        int ans = 0;
        while(!q.empty()){
            int tp = q.front();
            q.pop();
            visited[tp] = true;
            for(auto x : front[tp]){
                if(!visited[x]){
                    ans++;
                    q.push(x);
                }
            }
            for(auto x : back[tp]){
                if(!visited[x]){
                    q.push(x);
                }
            }
        }
        
        return ans;
    }
};