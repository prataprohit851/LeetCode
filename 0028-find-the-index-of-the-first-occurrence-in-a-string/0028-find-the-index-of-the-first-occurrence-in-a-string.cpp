class Solution {
public:
    int strStr(string haystack, string needle) {
        // if(haystack == needle) return 0;
        for(int i = 0; i < haystack.length(); i++){
            if(haystack[i] == needle[0]){
                if(i+needle.length() <= haystack.length() && haystack.substr(i,needle.length()) == needle) return i;
            }
        }
        return -1;
    }
};