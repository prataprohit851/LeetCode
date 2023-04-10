class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto x : s){
            if(x == '(' || x == '[' || x == '{') st.push(x);
            else{
                if(st.empty()) return false;
                char t = st.top();
                st.pop();
                if(x == ')' && t != '(') return false;
                if(x == ']' && t != '[') return false;
                if(x == '}' && t != '{') return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};