class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = words.size();
        int m = words[0].size();
        
        if(s.length() < m*n) return ans;
        
        unordered_map<string, int> mp;
        
        for(auto word : words) mp[word]++;
        for(int i = 0; i <= s.length()- (m*n); i++){
            unordered_map<string, int> mp2 = mp;
            int j;
            for(j = 0; j < n; j++){
                string str = s.substr(i + j*m, m);
                if(mp2.find(str) == mp2.end()) break;
                else{
                    if(mp2[str] == 0) break;
                    else mp2[str]--;
                }
            }
            if(j == n) ans.push_back(i);
        }
        return ans;
    }
};