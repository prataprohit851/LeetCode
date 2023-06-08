class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int r = n-1;
        int c = 0;
        int ans = 0;
        while(r >= 0 && c < m){
            if(grid[r][c] >= 0){
                c++;
            }
            else{
                r--;
                ans += m-c;
            }
        }
        return ans;
    }
};