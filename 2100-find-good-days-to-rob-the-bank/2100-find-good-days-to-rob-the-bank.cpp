class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int t) {
        int n = s.size();
        vector<int> LTR(n, 0);
        vector<int> RTL(n, 0);
        
        vector<int> ans;
        
        if(t >= n/2+1) return ans;
        
        for(int i = 1; i < n; i++){
            if(s[i] <= s[i-1]) LTR[i] = LTR[i-1] + 1;
        }
        for(int i = n-2; i >= 0; i--){
            if(s[i] <= s[i+1]) RTL[i] = RTL[i+1] + 1;
        }
        
        for(int i = t; i < s.size()-t; i++){
            if(LTR[i] >= t && RTL[i] >= t) ans.push_back(i);
        }
        
        return ans;
    }
};