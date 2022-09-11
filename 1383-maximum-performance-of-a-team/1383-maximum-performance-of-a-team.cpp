class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> worker( efficiency.size());
        for(int i = 0; i < efficiency.size(); i++){
            worker[i].first = efficiency[i];
            worker[i].second = speed[i];
        }
        sort(worker.begin(), worker.end(), cmp);
        long ans = 0;
        long spd = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        
        for(int i = 0; i < efficiency.size(); i++){
            if(q.size() == k){
                spd -= q.top();
                q.pop();
            }
            spd += worker[i].second;
            q.push(worker[i].second);
            ans = max(ans, worker[i].first * spd);
        }
        return ans % (int) (1e9+7);
    }
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
    }
};