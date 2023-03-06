class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        int ind = 0;
        while(ind < arr.size()){
            if(num != arr[ind]){
                k--;
            }
            else ind++;
            num++;
            if(k == 0) break;
        }
        if(k != 0) num = num+k;
        return num-1;
    }
};