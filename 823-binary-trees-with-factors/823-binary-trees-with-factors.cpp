class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int, int> mp;
        int MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        
        for(auto ele : arr){
            mp[ele] = 1;
        }
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] == 0){
                    int num = arr[i] / arr[j];
                    auto it = mp.find(num);
                    if(it != mp.end()){
                        mp[arr[i]] = ((long long)mp[arr[i]] + ((long long)mp[arr[j]] * (long long)it->second)% MOD) % MOD;
                    }
                }
            }
        }
        int count = 0;
        for(auto ele : mp){
            count = ((long long)count + (long long)ele.second) % MOD;
        }
        return count;
    }
};