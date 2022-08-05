class Solution {
public:
    map<int, int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0) return 1;
        auto it = dp.find(target);
        if(it != dp.end()) return it->second;
        int ans = 0;
        for(auto num : nums){
            if(num <= target)ans += combinationSum4(nums, target - num);
        }
        dp.insert({target, ans});
        return ans;
    }
};