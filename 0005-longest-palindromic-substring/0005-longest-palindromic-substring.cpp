class Solution {
public:
    string longestPalindrome(string s) {

        int LPSSI = 0;
        int LPSLL = 0;

        for(int i = 0; i < s.length(); i++){

            int right = i;
            while(right < s.length() && s[i] == s[right]) right++;
            int left = i-1;
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                left--;
                right++;
            }
            int len = right - left - 1;
            if(LPSLL < len){
                LPSLL = len;
                LPSSI = left + 1;
            }
        }
        return s.substr(LPSSI, LPSLL);
    }
};