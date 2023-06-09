class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        for(int i = letters.size()-1; i >= 0; i--){
            if(letters[i] > target) ans = letters[i];
        }
        return ans;
    }
};