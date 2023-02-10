class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) q.push({i,j});
            }

        }
        int ans = -1;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                pair<int, int> p = q.front();
                q.pop();
                if(p.first != 0 && !grid[p.first-1][p.second]){
                    grid[p.first-1][p.second] = 1;
                    q.push({p.first-1, p.second});
                }
                if(p.first != grid.size()-1 && !grid[p.first+1][p.second]){
                    grid[p.first+1][p.second] = 1;
                    q.push({p.first+1, p.second});
                }
                if(p.second != 0 && !grid[p.first][p.second-1]){
                    grid[p.first][p.second-1] = 1;
                    q.push({p.first, p.second-1});
                }
                if(p.second != grid[0].size()-1 && !grid[p.first][p.second+1]){
                    grid[p.first][p.second+1] = 1;
                    q.push({p.first, p.second+1});
                }
            }
        }
        return (ans == 0) ? -1 : ans;
    }
};