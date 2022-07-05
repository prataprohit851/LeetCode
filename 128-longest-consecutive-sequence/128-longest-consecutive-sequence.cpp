class Solution {
public:
    int longestConsecutive(vector<int>& s) {
        unordered_set<int> ht;
        
        for(auto ele : s) ht.insert(ele);
        int longest = 0;
        for(int i = 0; i < s.size(); i++){
            if(ht.find(s[i]-1) == ht.end()){
                int length = 0;
                while(ht.find(s[i] + length) != ht.end()){
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};