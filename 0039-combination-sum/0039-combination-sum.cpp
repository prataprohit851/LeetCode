class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, target, 0, {});
        return ans;
    }
    void helper(vector<int>& c, int t, int ind, vector<int> ds){
        if(ind == c.size()){
            if(t == 0) ans.push_back(ds);
            return;
        } 
        //cout<<t<<endl;
        helper(c, t, ind+1, ds);
        if(c[ind] <= t){
            ds.push_back(c[ind]);
            helper(c, t-c[ind], ind, ds);
        }
    }
};