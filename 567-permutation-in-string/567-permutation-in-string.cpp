class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> HT(26, 0);
        for(int i = 0; i < s1.length(); i++) HT[s1[i]-'a']++;
        for(int i = 0; i < s2.length(); i++) {
            if(HT[s2[i]-'a'] != 0){
                vector<int> temp = HT;
                for(int j = i; j < s2.length(); j++){
                    if(temp[s2[j]-'a'] == 0 ) break;
                    temp[s2[j]-'a']--;
                }
                int zero = 0;
                for(int j = 0; j < temp.size(); j++) zero = max(zero, temp[j]);
                if(zero == 0) return true;
            }
        }
        return false;
    }
};