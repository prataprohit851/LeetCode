class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        string ans = "";
        int carry = 0;
        while(i >= 0 || j >= 0 || carry!= 0){
            int sum = carry;
            if(i >= 0){
                carry += (a[i]=='0')?0:1;
                i--;
            }
            if(j >= 0){
                carry += (b[j]=='0')?0:1;
                j--;
            }
            ans = (((carry%2)==0)?"0":"1") + ans;
            carry /= 2;
        }
        return ans;
    }
};