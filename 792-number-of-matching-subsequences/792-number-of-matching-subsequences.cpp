class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<int>> ht;
        for(int i = 0; i < s.length(); i++)
            ht[s[i]].push_back(i);
        
        int count = 0;
        for(auto word : words){
            int lastInd = -1;
            for(int i = 0; i < word.length(); i++){
                auto it = upper_bound(ht[word[i]].begin(), ht[word[i]].end(), lastInd);
                if(it == ht[word[i]].end()) break;
                lastInd = *it;
                if(i == word.length()-1) count++;
            }
        }
        return count;
    }
};