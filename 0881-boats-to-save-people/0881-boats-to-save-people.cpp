class Solution {
public:
    int numRescueBoats(vector<int>& p, int lim) {
        sort(p.begin(), p.end());
        int l = 0, h = p.size()-1;
        int ans = 0;
        while(l <= h){
            if(lim-p[h] >= p[l]) l++;
            ans++;
            h--;
        }
        return ans;
    }
};