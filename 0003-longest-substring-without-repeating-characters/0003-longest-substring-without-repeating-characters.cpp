class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<char> st;
       int i = 0;
       int j = 0;
       int ans = 0;
       while(i < s.length() && j < s.length()){
           if(st.find(s[j]) == st.end()){
               st.insert(s[j++]);
               ans = max(ans, j-i);
           }
           else{
               st.erase(s[i++]);
           }
       } 
       return ans;
    }
};