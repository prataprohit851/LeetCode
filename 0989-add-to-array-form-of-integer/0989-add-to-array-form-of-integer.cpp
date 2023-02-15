class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> mum;
        while(k != 0){
            mum.insert(mum.begin(), k%10);
            k = k/10;
        }
        int carry = 0;
        int i = num.size()-1;
        int j = mum.size()-1;
        vector<int> ans;
        while(i >= 0 || j >= 0 || carry != 0){
            if(i >= 0){
                carry += num[i--];
            }
            if(j >= 0){
                carry += mum[j--];
            }
            ans.insert(ans.begin(), carry%10);
            carry = carry/10;
        }
        return ans;
    }
};