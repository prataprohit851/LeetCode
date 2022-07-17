class Solution {
public:
    string sortSentence(string s) {
        vector<string> st;
        s += " ";
        string temp = "";
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                st.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        sort(st.begin(), st.end(), comp);
        string ans = "";
        
        for(auto ele : st)
            ans += ele.substr(0, ele.length()-1) + " ";
        
        return ans.substr(0, ans.length()-1);
    }
    
    static bool comp(string a, string b){
        return (a[a.length()-1] < b[b.length()-1]) ? true : false;
    }
};