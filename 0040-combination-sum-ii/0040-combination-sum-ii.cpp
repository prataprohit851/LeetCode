class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, {});
        return ans;
    }
    void helper(vector<int>& c, int t, int ind, vector<int> ds){

        //if(ind == c.size()){
            if(t == 0){
                ans.push_back(ds);
                return;
            } 
            //return;
        //}


        for(int i = ind; i < c.size(); i++){
            if(i > ind && c[i] == c[i-1]) continue;
            if(c[i] > t) break;
            ds.push_back(c[i]);
            helper(c, t-c[i], i+1, ds);
            ds.pop_back();
        }
    }
};