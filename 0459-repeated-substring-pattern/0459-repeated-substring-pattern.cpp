class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i=1; i < s.length()/2+1; i++){
            string substring = s.substr(0, i);
            string t = substring;
            while(t.length() < s.length()) t += substring;
            if(t == s) return true;
        }
        return false;
    }
};