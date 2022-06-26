class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        helper(image, sr, sc, color, image[sr][sc]);
        return image;
    }
    
    void helper(vector<vector<int>>& grid, int r, int c, int colToChange, int currCol){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == colToChange|| grid[r][c] != currCol) return;
        
        grid[r][c] = colToChange;
        
        helper(grid, r-1, c, colToChange, currCol);
        helper(grid, r+1, c, colToChange, currCol);
        helper(grid, r, c-1, colToChange, currCol);
        helper(grid, r, c+1, colToChange, currCol);
    }
};