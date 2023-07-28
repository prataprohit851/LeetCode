class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1;
        int suf = 1;
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            pre *= nums[i];
            suf *= nums[nums.size()-i-1];
            ans = max(ans, max(pre, suf));
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
        }
        return ans;
    }
};