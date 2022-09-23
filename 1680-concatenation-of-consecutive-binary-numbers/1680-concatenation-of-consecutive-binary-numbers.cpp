class Solution {
public:
    int noOfBits(int n){
        return log2(n) + 1;
    }
    int concatenatedBinary(int n) {
        long ans = 0;
        long mod = 1e9+7;
        for(int i = 1; i <= n; ++i){
            int len = noOfBits(i);
            ans = ((ans << len) % mod + i) % mod;
        }
        return ans;
    }
};