class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        bool flag = true;
        for(int i = 0, j = n; j < 2*n;){
            if(flag){
                ans.push_back(nums[i++]);
            }
            else{
                ans.push_back(nums[j++]);
            }
            flag = !flag;
        }
        return ans;
    }
};