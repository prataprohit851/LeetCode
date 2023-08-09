class Solution {
public:
    int beautySum(string s) {
        
        int ans = 0;

        for(int i = 0; i < s.length(); i++){
            vector<int> freq(26, 0);
            for(int j = i; j < s.length(); j++){
                freq[s[j]-'a']++;
                int min_ele = INT_MAX;
                for(auto x : freq) if(x > 0) min_ele = min(x, min_ele);
                if(j-i > 1) ans += (*max_element(freq.begin(), freq.end()) - min_ele);
            }
        }

        return ans;
    }
};