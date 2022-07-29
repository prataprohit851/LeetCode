class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& w, string p) {
        string pattern = getPattern(p); 
        vector<string> ans;
        for(auto ele : w){
            if(pattern == getPattern(ele)){
                ans.push_back(ele);
            }
        }
        return ans;
    }
    
    string getPattern(string s){
        map<char, int> mp;
        int j = 1;
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            auto it = mp.find(s[i]);
            if(it == mp.end()){
                mp[s[i]] = j;
                ans = ans + (char)j;
                j++;
            }
            else{
                ans += (char)it->second;
            }
        }
        return ans;
    }
};