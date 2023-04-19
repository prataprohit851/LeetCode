class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
    static bool comp(int a, int b){
        int _a = __builtin_popcount(a);
        int _b = __builtin_popcount(b);
        if(_a == _b) return a < b;
        else return _a <= _b;
    }
};