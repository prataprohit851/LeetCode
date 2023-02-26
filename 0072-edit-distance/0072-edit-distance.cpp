
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int dp[m+1][n+1];
        for(int i = 0; i <= m; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i <= n; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int del = dp[i-1][j];
                    int rep = dp[i][j-1];
                    int exc = dp[i-1][j-1];
                    dp[i][j] = 1 + min({del, rep, exc});
                }
            }
        }
        return dp[m][n];
    }
};



// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         return helper(word1, word2, 0);
//     }
//     int helper(string s, string t, int ans){
//         cout<<s<<" "<<t<<endl;
//         if(s == t) return 0;
//         if(s == "") return t.length();
//         if(t == "") return s.length();
        
//         if(s[s.length()-1] == t[t.length()-1]){
//             return helper(s.substr(0,s.length()-1), t.substr(0,t.length()-1), ans);
//         }
//         else{
//             int temp = INT_MAX;
//             temp = min(helper(s.substr(0,s.length()), t.substr(0,t.length()-1), ans), helper(s.substr(0,s.length()-1), t.substr(0,t.length()), ans));
//             temp = min(temp, helper(s.substr(0,s.length()-1), t.substr(0,t.length()-1), ans));
//             ans += temp + 1;
//         }
//         return ans;
//     }
// };