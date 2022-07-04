class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int cookieInd = 0;
        int bacchaInd = 0;
        
        int count = 0;
        
        while(cookieInd < s.size() && bacchaInd < g.size()){
            
            if(g[bacchaInd] <= s[cookieInd]){
                bacchaInd++;
                cookieInd++;
                count++;
            }
            else cookieInd++;
        }
        return count;
    }
};