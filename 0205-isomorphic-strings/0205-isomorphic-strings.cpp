class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp;
        for(int i = 0; i < s.length(); i++){
            auto curr = mp.find(s[i]);
            if(curr == mp.end()){
                mp[s[i]] = t[i];
            }
            if(mp[s[i]] != t[i]) return false;
        }

        mp.clear();

        for(int i = 0; i < t.length(); i++){
            auto curr = mp.find(t[i]);
            if(curr == mp.end()){
                mp[t[i]] = s[i];
            }
            if(mp[t[i]] != s[i]) return false;
        }
        return true;
    }
};