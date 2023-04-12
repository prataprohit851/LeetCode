class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int ct = 0;
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] != s2[i]) ct++;
        }
        if(ct < 3){
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            return s1 == s2;
        }
        return false;
    }
};