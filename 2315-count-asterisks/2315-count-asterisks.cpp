class Solution {
public:
    int countAsterisks(string s) {
        bool ins = false;
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(!ins && s[i] == '*') count++;
            if(s[i] == '|') {
                ins = !ins;
            }
        }
        return count;
    }
};
