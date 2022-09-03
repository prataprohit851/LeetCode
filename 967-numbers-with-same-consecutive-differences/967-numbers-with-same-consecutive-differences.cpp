class Solution {
public:
    vector<int> ans;
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i < 10; i++)
            findNumber(i, n, k);
        return ans;
    }
    void findNumber(int i, int n, int k){
        if(numberSize(i) == n){
            ans.push_back(i);
            return;
        }
        for(int j = 0; j < 10; j++){
            if(abs(i%10 - j) == k){
                int number = i*10 + j;
                findNumber(number, n, k);
            }
        }
    }
    int numberSize(int n){
        int count = 0;
        while(n > 0){
            n =n / 10;
            count++;
        }
        return count;
    }
};