class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(i != 0 && arr[i] != arr[i-1]) count = 0;
            count++;
            if(count > n/4) return arr[i];
        }
        return -1;
    }
};