class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> subsets;
        getSubset(1, n, {}, subsets, k);
        return subsets;
    }
    void getSubset(int start, int end, vector<int> curr, vector<vector<int>>& res, int k){
        if(curr.size() == k){
            res.push_back(curr);
            return;
        }
        for(int i = start; i <= end; i++){
            curr.push_back(i);
            getSubset(i + 1, end, curr, res, k);
            curr.erase(curr.end()-1);
        }
    }
};