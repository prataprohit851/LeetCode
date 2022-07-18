class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();
        int j = n-1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int sum = nums[i] + nums[j-i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};