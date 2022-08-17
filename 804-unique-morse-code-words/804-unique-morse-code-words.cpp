class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<char, string> morse = {
            {'a', ".-"},
            {'b', "-..."},
            {'c', "-.-."},
            {'d', "-.."},
            {'e', "."},
            {'f', "..-."},
            {'g', "--."},
            {'h', "...."},
            {'i', ".."},
            {'j', ".---"},
            {'k', "-.-"},
            {'l', ".-.."},
            {'m', "--"},
            {'n', "-."},
            {'o', "---"},
            {'p', ".--."},
            {'q', "--.-"},
            {'r', ".-."},
            {'s', "..."},
            {'t', "-"},
            {'u', "..-"},
            {'v', "...-"},
            {'w', ".--"},
            {'x', "-..-"},
            {'y', "-.--"},
            {'z', "--.."}
        };
        map<string, int> mp;
        for(int i = 0; i < words.size(); i++){
            string s = "";
            for(int j = 0; j < words[i].size(); j++) s = s + morse[words[i][j]];
            mp[s]++;
        }
        return mp.size();
    }
};