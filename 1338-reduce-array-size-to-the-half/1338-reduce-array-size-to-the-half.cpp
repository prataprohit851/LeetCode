class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto ele : arr) mp[ele]++;
        priority_queue<int> q;
        for(auto ele : mp) q.push(ele.second);
        int ans = 0;
        int rem = 0;
        int n = arr.size();
        while(rem < n/2){
            rem += q.top();
            q.pop();
            ans++;
        }
        return ans;
    }
};