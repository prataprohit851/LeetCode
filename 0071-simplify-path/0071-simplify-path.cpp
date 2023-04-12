class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        while(i < path.length()){
            string s = "";
            cout<<i<<endl;
            while(i < path.length() && path[i] != '/') s += path[i++];
            if(s == ".") continue;
            else if(s == ".."){
                if(!st.size()) continue;
                st.pop();
            }
            else if(s != "")st.push(s);
            i++;
        }
        string ans = "";
        while(st.size()){
            ans = "/" + st.top() + ans;
            // st2.push(st.top());
            st.pop();
        }
        return (ans == "") ? "/" : ans;
    }
};