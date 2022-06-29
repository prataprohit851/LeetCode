class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> phash(26, 0);
        vector<int> hash(26, 0);
        vector<int> ans;
        
        if(p.length() > s.length()) return ans;
        
        for(int i = 0; i < p.length(); i++) phash[p[i]-'a']++, hash[s[i]-'a']++;
        
        int left = 0, right = p.length()-1;
        
        while(right < s.length()-1){
            if(phash == hash) ans.push_back(left);
            hash[s[++right] - 'a']++;
            hash[s[left++] - 'a']--;
        }
        
        if(phash == hash) ans.push_back(left);
        
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         if(p.length() > s.length()) return {};
//         vector<int> ht(26, 0);
//         for(int i = 0; i < p.length(); i++) ht[p[i]-'a']++;
//         vector<int> ans;
//         for(int i = 0; i <= s.length()-p.length(); i++){
//             if(ht[s[i]-'a'] == 0) continue;
//             int temp = p.length();
//             vector<int> ht2 = ht;
//             for(int j = i; j < i+p.length(); j++){
//                 if(ht2[s[j]-'a'] == 0) continue;
//                 ht2[s[j]-'a']--;
//                 temp--;
//             }
//             if(temp == 0) ans.push_back(i);
//         }
//         return ans;
//     }
// };