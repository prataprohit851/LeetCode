class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> combinationSum3(int k, int n) {
        helper(0, k, n, {});
        return ans;
    }
    void helper(int ind, int k, int n, vector<int> ds){
        if(ind == 9) {
            if(k == 0 && n == 0){
                ans.push_back(ds);
            }
            return;
        }
        helper(ind+1, k, n, ds);
        ds.push_back(nums[ind]);
        if(nums[ind] <= n) helper(ind+1, k-1, n-nums[ind], ds);
    }
};