class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i < strs[0].length(); i++){
            bool flag = true;
            char temp = strs[0][i];
            for(auto& x : strs){
                if(x[i] != temp){
                    flag = false;
                    break;
                }
            }
            if(flag) ans += strs[0][i];
            else break;
        }
        return ans;
    }
};