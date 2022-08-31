class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> pacific(heights.size(), vector<int> (heights[0].size(), 0));
        vector<vector<int>> atlantic(heights.size(), vector<int> (heights[0].size(), 0));
        vector<vector<int>> ans;
        
        for(int i = 0; i < heights.size(); i++){
            helper(i, 0, heights, pacific, INT_MIN);
            helper(i, heights[0].size()-1, heights, atlantic, INT_MIN);
        }
        for(int i = 0; i < heights[0].size(); i++){
            helper(0, i, heights, pacific, INT_MIN);
            helper(heights.size()-1, i, heights, atlantic, INT_MIN);
        }
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(atlantic[i][j] == 1 && pacific[i][j] == 1){
                    vector<int> v (2);
                    v[0] = i;
                    v[1] = j;
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
    
    void helper(int i, int j, vector<vector<int>> &heights, vector<vector<int>> &ocean, int prev){
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) return;
        if(ocean[i][j] == 1) return;
        if(heights[i][j] < prev) return;
        
        ocean[i][j] = 1;
        
        helper(i+1, j, heights, ocean, heights[i][j]);
        helper(i, j+1, heights, ocean, heights[i][j]);
        helper(i-1, j, heights, ocean, heights[i][j]);
        helper(i, j-1, heights, ocean, heights[i][j]);
    }
};