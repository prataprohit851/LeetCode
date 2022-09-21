class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int even = 0;
        for(int i : nums)
            if(i % 2 == 0) even += i;
        vector<int> ans;
        for(int i = 0; i < q.size(); i++){
            if(nums[q[i][1]] % 2 == 0){
                //even
                even -= nums[q[i][1]];
                nums[q[i][1]] = nums[q[i][1]] + q[i][0];
                if(nums[q[i][1]] % 2 == 0){
                    even += nums[q[i][1]];
                }
            }
            else{
                //odd
                nums[q[i][1]] = nums[q[i][1]] + q[i][0];
                if(nums[q[i][1]] % 2 == 0){
                    even += nums[q[i][1]];
                }
            }
            ans.push_back(even);
        }
        return ans;
    }
};