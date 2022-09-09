class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        int ans = 0;
        int n = properties.size();
        int min = INT_MIN;
        for(int i = n-1; i >=0; i--){
            if(properties[i][1] < min) ans++;
            min = max(min, properties[i][1]);
        }
        return ans;
    }
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }
};