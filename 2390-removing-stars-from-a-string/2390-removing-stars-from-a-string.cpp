class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto x : s){
            if(x != '*') st.push(x);
            else st.pop();
        }
        string ans = "";
        while(st.size()) ans += st.top(), st.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};