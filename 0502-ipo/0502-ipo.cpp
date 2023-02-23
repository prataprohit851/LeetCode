class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> hashMap(n);
        
        for(int i = 0; i < n; i++){
            hashMap[i] = {profits[i], capital[i]};
        }
        sort(hashMap.begin(), hashMap.end(), helper);
        priority_queue<int> q;
        int i = 0;
        while(k--){
            while(i < n && hashMap[i].second <= w){
                q.push(hashMap[i].first);
                i++;
            }
            if(!q.empty()) w+=q.top(), q.pop();
        }
        
        return w;
    }
    static bool helper(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
};