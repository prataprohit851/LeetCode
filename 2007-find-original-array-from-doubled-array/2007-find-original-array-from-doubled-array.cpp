class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 != 0) return {};
        sort(changed.begin(), changed.end());
        map<int, int> mp;
        for(int i = 0; i < changed.size(); i++) mp[changed[i]]++;
        vector<int> ans;
        for(int x : changed){
            if(mp[x] == 0) continue;
            if(mp[2*x] == 0) return {};
            if(mp[x] && mp[2*x]){
                ans.push_back(x);
                mp[x]--;
                mp[2*x]--;
            }
        }
        return ans;
    }
};