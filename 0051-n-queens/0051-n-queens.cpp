class Solution {
public:
    vector<vector<string>> ans;
    set<pair<int, int>> occupied_places;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> ds;
        helper(0, n, ds);
        return ans;
    }
    void helper(int col, int n, vector<string>& ds){

        

        for(int row = 0; row < n; row++){
            bool placable = true;
            for(auto x : occupied_places){
                if(row == x.first || col == x.second || x.first + x.second == row + col || x.first - x.second == row - col){
                    placable = false;
                    break;
                }
            }
            
            if(placable){
                string s = "";
                for(int i = 0; i < n; i++){
                    string t = (i == row) ? "Q" : ".";
                    s += t;
                }
                ds.push_back(s);
                occupied_places.insert({row, col});
                helper(col+1, n, ds);
                occupied_places.erase(occupied_places.find({row, col}));
                ds.pop_back();
            }
        }

        
        if(col == n) ans.push_back(ds);
    }
};