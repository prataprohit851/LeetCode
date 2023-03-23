class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        int extC = 0;
        map<int, vector<int>> mp;
        for(int i = 0; i < connections.size(); i++){
            mp[connections[i][0]].push_back(connections[i][1]);
            mp[connections[i][1]].push_back(connections[i][0]);
        }
        queue<int> q;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                visited[i] = true;
                extC++;
                q.push(i);
                while(!q.empty()){
                    int tp = q.front();
                    cout<<tp<<" ";
                    q.pop();
                    for(auto x : mp[tp]){
                        if(!visited[x]){
                            q.push(x);
                            visited[x] = true;
                        }
                    }
                }
            }
        }
        return extC-1;
    }
};