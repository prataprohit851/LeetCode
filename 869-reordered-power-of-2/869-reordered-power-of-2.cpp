class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> countn = count(n);
        int k = 1;
        for(int i = 0; i < 31; i++){
            if(countn == count(k)) return true;
            k = k << 1;
        }
        return false;
    }
    vector<int> count (int n){
        vector<int> ans(10, 0);
        while(n > 0){
            ans[n%10]++;
            n /= 10;
        }
        return ans;
    }
};