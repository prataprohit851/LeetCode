class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        int count = 0;
        int ini = startPos[0];
        int inj = startPos[1];
        for(int  i = 0; i < s.length(); i++){
            for(int  j = i; j < s.length(); j++){
                if(s[j] == 'R') startPos[1]++;
                else if(s[j] == 'L') startPos[1]--;
                else if(s[j] == 'U') startPos[0]--;
                else if(s[j] == 'D') startPos[0]++;
                
                if(startPos[1] > -1 && startPos[1] < n && startPos[0] > -1 && startPos[0] < n) count++;
                else j = INT_MAX-1;
            }
            ans.push_back(count);
            count = 0;
            startPos = {ini, inj};
        }
        return ans;
    }
};