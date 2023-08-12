class Solution {
public:
    int myAtoi(string s) {

        double ans = 0;
        int ind = 0;

        while(s[ind] == ' '){
            ind++;
        }

        bool positive = s[ind] == '+';
        bool negative = s[ind] == '-';
        positive == true ? ind++ : ind;
        negative == true ? ind++ : ind;

        while(ind < s.length() && s[ind] <= '9' && s[ind] >= '0'){
            ans *= 10;
            ans += s[ind]-'0';
            ind++;
        }

        ans = (negative) ? -ans : ans;
        ans = (ans > INT_MAX) ? INT_MAX : ans;
        ans = (ans < INT_MIN) ? INT_MIN : ans; 

        return int(ans);
    }
};