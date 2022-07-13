class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> ht(26, 0);
        int n = s1.length();
        for(int i = 0; i < n; i++) ht[s1[i]-'a']++;
        
        int i = 0, j = 0;
        
        for(j = 0; j < n; j++) ht[s2[j]-'a']--;
        for(j = j-1; j < s2.length(); j++,i++){
            bool all = true;
            for(int check = 0; check < 26; check++){
                if(ht[check] != 0){
                    all = false;
                    check = 26;
                }
            }
            if(all) return true;
            ht[s2[i]-'a']++;
            if(j != s2.length()-1) ht[s2[j+1]-'a']--;
        }
        return false;
    }
};