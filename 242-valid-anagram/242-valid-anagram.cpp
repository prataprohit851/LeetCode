class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hashTable(26, 0);
        for(int i = 0; i < t.length(); i++){
            hashTable[t[i] - 'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            hashTable[s[i] - 'a']--;
        }
        for(auto ele : hashTable){
            if(ele != 0) return false;
        }
        return true;
    }
};