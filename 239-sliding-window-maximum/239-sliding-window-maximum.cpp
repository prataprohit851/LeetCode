class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        deque<int> dq;
        for(; j < k; j++){
            while(!dq.empty() && dq.back() < nums[j]) dq.pop_back();
            dq.push_back(nums[j]);
        }
        ans.push_back(dq.front());
        for(; j < nums.size(); i++, ++j){
            if(dq.front() == nums[i]) dq.pop_front();
            while(!dq.empty() && dq.back() < nums[j]) dq.pop_back();
            dq.push_back(nums[j]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};