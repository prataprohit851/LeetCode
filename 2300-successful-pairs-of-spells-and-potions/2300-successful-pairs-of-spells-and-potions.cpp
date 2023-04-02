class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        sort(p.begin(), p.end());
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            int l = 0, h = p.size()-1;
            int m;
            while(l <= h){
                m = h+(l-h)/2;
                if((long long)p[m]*(long long)s[i] >= success) h = m-1;
                else l = m+1;
            }
            ans.push_back(p.size()-1-h);
        }
        return ans;
    }
};