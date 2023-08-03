class Solution {
public:
    vector<string> key = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if(digits != "")helper(0, digits, "");
        return ans;
    }
    void helper(int ind, string& digits, string curr){

        if(ind == digits.size()){
            ans.push_back(curr);
            return;
        }

        string currKeyString = key[digits[ind]-'0'];
        
        for(int i = 0; i < currKeyString.length(); i++){
            helper(ind+1, digits, curr+currKeyString[i]);
        }
    }
};