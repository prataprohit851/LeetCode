class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int eC) {
        int mx = *max_element(c.begin(), c.end());
        vector<bool> ans(c.size(), false);
        for(int i = 0; i < c.size(); i++){
            if(c[i] + eC >= mx) ans[i] = true;
        }
        return ans;
    }
};