class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for(int i = 0; i < grid[0].size(); i++){
            dfs(0, i, grid, visited);
            dfs(grid.size()-1, i, grid, visited);
        }
        for(int i = 0; i < grid[0].size(); i++){
            dfs(i, 0, grid, visited);
            dfs(i, grid[0].size()-1, grid, visited);
        }
        for(int i = 1; i < grid.size()-1; i++){
            for(int j = 1; j < grid[0].size()-1; j++){
                if(grid[i][j] == 0 && !visited[i][j]){
                    ans++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return ans;
    }
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(row < 0 || row >= grid.size()) return;
        if(col < 0 || col >= grid[0].size()) return;
        
        if(grid[row][col] == 1) return;
        if(visited[row][col]) return;
        visited[row][col] = true;
        
        dfs(row+1, col, grid, visited);
        dfs(row, col+1, grid, visited);
        dfs(row-1, col, grid, visited);
        dfs(row, col-1, grid, visited);
    }
};