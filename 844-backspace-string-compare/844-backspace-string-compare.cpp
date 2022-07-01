class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> a;
        stack<int> b;
        
        for(int i = 0; i < s.size() || i < t.size(); i++){
            if(i < s.size()){
                if(s[i] != '#') a.push(s[i]);
                else if(!a.empty()) a.pop();
            }
            if(i < t.size()){
                if(t[i] != '#') b.push(t[i]);
                else if(!b.empty()) b.pop();
            }
        }
        return a == b;
    }
};