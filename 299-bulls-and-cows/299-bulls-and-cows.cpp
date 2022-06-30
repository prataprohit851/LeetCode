class Solution {
public:
    string getHint(string s, string g) {
        vector<char> ht;
        vector<char> ht2;
        for(int i = 0; i < s.size(); i++) ht.push_back(s[i]);
        int bullCount = 0;
        for(int i = 0; i < g.size(); i++){
            if(s[i] == g[i]) bullCount++;
            auto itr = find(ht.begin(), ht.end(), g[i]);
            if(itr != ht.end()) { 
                ht.erase(itr);
                ht2.push_back(g[i]);
            }
        }
        int cowCount = ht2.size()-bullCount;
        return to_string(bullCount) + "A" + to_string(cowCount) + "B";
    }
};