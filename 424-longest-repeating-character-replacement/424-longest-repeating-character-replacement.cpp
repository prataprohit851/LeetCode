class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> ht(26, 0);
        int window_left = 0;
        int window_right = 0;
        int maxEle = 0;
        int maxLength = 0;
        
        for(window_right = 0; window_right < s.length(); window_right++){
            ht[s[window_right]-'A']++;
            maxEle = max(maxEle, ht[s[window_right]-'A']);
            while((window_right-window_left+1) - maxEle > k ) ht[s[window_left++]-'A']--;
            maxLength = max(maxLength, window_right-window_left+1);
        }
        return maxLength;
    }
};