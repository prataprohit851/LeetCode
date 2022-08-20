class Solution {
public:
    int minimumRecolors(string s, int k) {
        int w = 0;
        for(int i = 0; i < k; i++){
            if(s[i] == 'W')w++;
        }
        int i = 0;
        int j = k-1;
        int ans = w;
        for(; j < s.length()-1; j++, i++){
            if(s[i] == 'W') w--;
            if(s[j+1] == 'W') w++;
            ans = min(ans, w);
        }
        return ans;
    }
};