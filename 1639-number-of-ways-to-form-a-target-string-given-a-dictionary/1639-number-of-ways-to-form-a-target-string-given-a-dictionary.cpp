// class Solution {
// public:
//     int numWays(vector<string>& words, string target) {
//         vector<vector<int>> dp(target.length()+1, vector<int>(words[0].size()+1, -1));
//         return dfs(0, 0, words, target, dp);
//     }
//     int dfs(int tInd, int wInd, vector<string>& words, string target, vector<vector<int>>& dp){
//         if(tInd >= target.length()) return 1;
//         if(wInd >= words[0].size()) return 0;
//         if(dp[tInd][wInd] != -1) return dp[tInd][wInd];
//         int ans = 0;
//         for(auto& x : words){
//             for(int i = wInd; i < x.length(); i++){
//                 if(x[i] == target[tInd]) ans += dfs(tInd+1, i+1, words, target, dp);
//             }
//         }
//         return dp[tInd][wInd] = ans;
//     }
// };



class Solution {
public:
    int mod = 1000000007;
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> dp(target.length()+1, vector<int>(words[0].size()+1, -1));
        vector<vector<int>> freqz(words[0].size(), vector<int>(26, 0));
        for(auto& x : words){
            for(int i = 0; i < x.length(); i++){
                freqz[i][x[i]-'a']++;
            }
        }
        return dfs(0, 0, words, target, dp, freqz);
    }
    long dfs(int tInd, int wInd, vector<string>& words, string target, vector<vector<int>>& dp, vector<vector<int>>& freqz){
        if(tInd >= target.length()) return 1;
        if(wInd >= words[0].size() || words[0].size() - wInd < target.size() - tInd) return 0;
        if(dp[tInd][wInd] != -1) return dp[tInd][wInd];
        long ans = 0;
        
        ans += dfs(tInd, wInd+1, words, target, dp, freqz);
        ans += freqz[wInd][target[tInd]-'a'] * dfs(tInd+1, wInd+1, words, target, dp, freqz);
        
        return dp[tInd][wInd] = ans % mod;
    }
};