class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ht;
        for(int i = 0; i < nums.size(); i++){
            ht[nums[i]]++;
        }
        priority_queue<pair<int, int>> q;
        for(auto it : ht){
            q.push({it.second, it.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};