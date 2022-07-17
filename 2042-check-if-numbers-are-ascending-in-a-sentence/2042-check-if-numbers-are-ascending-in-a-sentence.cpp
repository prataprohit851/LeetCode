class Solution {
public:
    bool areNumbersAscending(string s) {
        int lastNum = INT_MIN;
        
        for(int i = 0; i < s.length(); i++){
            if(isdigit(s[i])){
                int count = 0;
                int currNum = 0;
                while(isdigit(s[i])){
                    currNum = (currNum * pow(10, count++)) + (s[i]-'0');
                    i++;
                }
                cout<<currNum<<endl;
                if(currNum <= lastNum) return false;
                else lastNum = currNum;
            }
        }
        return true;
    }
};