class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // 01
        // 03
        // 06
        // 10
        // 15
        // 21
        long long ans = 0;
        int i = 0, j = -1;
        while(++j < nums.size()){
            if(nums[j] == 0){
                i = j;
                while(j < nums.size() && nums[j] == 0) j++;
                int sz = j-i;
                ans += calculate(sz);
            }
        }
        return ans;
    }
    long long calculate(int sz){
        long long ans = 1;
        int i = 2;
        while(--sz){
            ans += i;
            i++;
        }
        return ans;
    }
};