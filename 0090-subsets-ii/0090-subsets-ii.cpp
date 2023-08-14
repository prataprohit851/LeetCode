class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        sort(nums.begin(), nums.end());
        helper(nums, 0, ds);
        return ans;
    }
    void helper(vector<int>& nums, int ind, vector<int>& ds){
        //cout<<ind<<endl;
        ans.push_back(ds);
        for(int i = ind; i < nums.size(); i++){
            if(i != ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper(nums, i+1, ds);
            ds.pop_back();
        }
    }
};