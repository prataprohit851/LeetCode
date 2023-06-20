class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        long long curr = 0;

        if(2*k+1 > n) return ans;

        for(int i = 0; i < 2*k+1; i++){
            curr += nums[i];
        }
        ans[k] = curr/(2*k+1);
        for(int i = k+1; i < n-k; i++){
            curr += nums[k+i] - nums[i-k-1];
            ans[i] = curr/(2*k+1);
        }
        return ans;
    }
};