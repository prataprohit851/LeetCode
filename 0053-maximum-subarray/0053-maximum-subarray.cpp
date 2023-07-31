class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int temp = 0;
        for(auto x : nums){
            temp += x;
            ans = max(ans, temp);
            if(temp < 0) temp = 0;
        }
        return ans;
    }
};