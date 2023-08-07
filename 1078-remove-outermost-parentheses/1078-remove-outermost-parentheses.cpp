class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        for(char x : s){
            if(x == '('){
                if(count > 0){
                    ans += x;
                }
                count++;
            }
            else{
                if(count > 1){
                    ans += x;
                }
                count--;
            }
        }
        return ans;
    }
};