class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> freq(26);
        for(char x : s){
            freq[x-'a']++;
        }
        for(char x : t){
            freq[x-'a']--;
            if(freq[x-'a'] < 0) return false;
        }
        return true;
    }
};