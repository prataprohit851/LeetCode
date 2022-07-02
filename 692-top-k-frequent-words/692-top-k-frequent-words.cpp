class Solution {
public:
    static bool comp(pair<string,int> p1, pair<string,int> p2){
        if(p1.second == p2.second) return p1.first < p2.first;
        return p1.second > p2.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashmap;
        for(auto ele : words) hashmap[ele]++;
        vector<pair<string, int>> vp;
        for(auto ele : hashmap) vp.push_back({ele.first, ele.second});
        sort(vp.begin(), vp.end(), comp);
        vector<string> ans;
        for(int i = 0; i < k; i++) ans.push_back(vp[i].first);
        return ans;
    }
};