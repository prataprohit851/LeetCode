class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(0, nums, {});
        return ans;
    }
    void helper(int ind, vector<int>& nums, vector<int> curr){
        if(ind == nums.size()){
            ans.push_back(curr);
            return;
        }
        helper(ind+1, nums, curr);
        curr.push_back(nums[ind]);
        helper(ind+1, nums, curr);
    }
};