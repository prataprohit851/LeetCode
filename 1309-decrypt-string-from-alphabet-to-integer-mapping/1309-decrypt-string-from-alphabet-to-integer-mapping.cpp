class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        int i = s.length() - 1;
        while(i >= 0){
            cout<<i<<" "<<ans<<endl;
            if(s[i] == '#'){
                i--;
                ans = (char)(((s[i]- '0') + (s[i-1]- '0') * 10) + 'a' - 1) + ans;
                i -= 2;
            }
            else{
                ans = (char)(s[i]- '0' + 'a' - 1) + ans;
                i--;
            }
        }
        return ans;
    }
};