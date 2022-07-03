class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        getPerm(visited, nums, {}, ans);
        return ans;
    }
    
    void getPerm(vector<bool>& visited, vector<int>& nums, vector<int> curr, vector<vector<int>>& ans){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == true) continue;
            curr.push_back(nums[i]);
            visited[i] = true;
            getPerm(visited, nums, curr, ans);
            curr.erase(curr.end()-1);
            visited[i] = false;
        }
    }
};