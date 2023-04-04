class Solution {
public:
    int partitionString(string s) {
        set<char> st;
        int ans = 0;
        for(auto x : s){
            if(st.find(x) != st.end()){
                st.clear();
                ans++;
            }
            st.insert(x);
        }
        return ++ans;
    }
};