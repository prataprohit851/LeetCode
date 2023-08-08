class Solution {
public:
    string reverseWords(string s) {
        int i = s.size()-1;

        while(i >= 0 && s[i] == ' ') i--;
        s = s.substr(0, i+1);
        while(i >= 0 && s[i] != ' ') i--;
        int start_ind = i+1;

        while(i >= 0){
            int sz = 0;
            cout<<i<<endl;
            while(i >= 0 && s[i] == ' ') i--;
            while(i >= 0 && s[i] != ' '){
                sz++;
                i--;
            }
            s += " " + s.substr(i+1, sz);
            while(i >= 0 && s[i] == ' ') i--;
        }

        return s.substr(start_ind, s.size()-start_ind);;
        
    }
};