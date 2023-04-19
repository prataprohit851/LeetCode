class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> vec(26, 0);
        for(auto& x : s) vec[x-'a']++;
        for(auto& x : t){
            vec[x-'a']--;
            if(vec[x-'a'] < 0) return false;
        }
        return true;
    }
};