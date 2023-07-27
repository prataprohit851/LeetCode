class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int summation = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            summation += i+1;
            sum += nums[i];
        }
        return (summation-sum);
    }
};