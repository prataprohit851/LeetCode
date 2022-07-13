class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        unordered_map<char, int> ht;
        for(int i = 0; i < t.length(); i++){
            ht[t[i]]++;
        }
        
        int leftWindow = 0;
        int count = 0;
        int small_len = INT_MAX;
        int small_i = -1;
        
        for(int rightWindow = 0; rightWindow < s.length(); rightWindow++){
            if(ht[s[rightWindow]] > 0) count++;
            ht[s[rightWindow]]--;
            
            while(count == t.length()){
                if(small_len > rightWindow-leftWindow+1){
                    small_i = leftWindow;
                    small_len = rightWindow-leftWindow+1;
                }
                ht[s[leftWindow]]++;
                if(ht[s[leftWindow]] > 0)count--;
                
                leftWindow++;
            }
        }
        return (small_len == INT_MAX) ? "" : s.substr(small_i, small_len);
    }
};