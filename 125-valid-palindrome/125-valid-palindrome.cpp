class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i < j){
            while(i < s.length() && !isalpha(s[i]) && !isdigit(s[i])) i++;
            while(j >= 0 && !isalpha(s[j]) && !isdigit(s[j])) j--;
            if(i == s.length() || j < 0) return true;
            if(islower(s[i])) s[i] = toupper(s[i]);
            if(islower(s[j])) s[j] = toupper(s[j]);
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
};