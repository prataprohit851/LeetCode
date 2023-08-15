class Solution {
public:
    set<string> st;
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x : wordDict) st.insert(x);
        // st.insert("");
        vector<int> dp(s.length(), -1);
        return helper(0, s, dp);
    }
    bool helper(int ind, string s, vector<int>& dp ){
        if(ind == s.length()) return true;
        if(dp[ind] != -1) return (dp[ind] == 1) ? true : false;
        for(int i = ind; i < s.length(); i++){
            if(st.find(s.substr(ind, i-ind+1)) != st.end() && helper(i+1, s, dp)){
                dp[ind] = 1;
                return true;
            }
        }
        dp[ind] = 0;
        return false;
    }
};