class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        q.push(make_pair(nums[0], 0));
        int maxScore = nums[0];
        for(int i = 1; i < nums.size(); i++){
            while(q.top().second < i-k) q.pop();
            maxScore = nums[i] + q.top().first;
            q.push({nums[i] + q.top().first, i});
        }
        return maxScore;
    }
};

// class Solution {
// public:
//     vector<int> dp;
//     int maxResult(vector<int>& nums, int k) {
//         dp = vector<int> (nums.size(), INT_MIN);
//         return helper(nums,k,0);
//     }
//     int helper(vector<int>& nums, int k, int i){
//         if(i >= nums.size()-1) return dp[i] = nums[i];
//         if(dp[i] != INT_MIN) return dp[i];
//         int n = nums.size()-1;
//         int maxScore = INT_MIN;
//         for(int j = i; j < min(n,i+k); j++){
//             maxScore = max(maxScore, nums[i] + helper(nums, k, j+1));
//         }
//         return dp[i] = maxScore;
//     }
// };