class Solution {
public:
    string reverseWords(string s) {
        int j = 0;
        s.append(" ");
        for(int i = 0; i < s.length(); i++){
            while(s[j] != ' '){
                j++;
            }
            j--;
            while(i < j){
                swap(s[j], s[i]);
                i++;
                j--;
            }
            j = i;
            while(s[j] != ' '){
                j++;
                i++;
            }
            j++;
        }
        s.erase(s.end()-1);
        return s;
    }
};