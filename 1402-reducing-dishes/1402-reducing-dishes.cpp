class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        int start = s.size()-1;
        int total = 0;
        for(int i = start; i >= 0; i--){
            total += s[i];
            if(total < 0) break;
            start--;
        }
        start++;
        total = 0;
        int k = 1;
        for(int i = start; i < s.size(); i++){
            total += ((k++)*(s[i]));
        }
        return total;
    }
};