class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        sort(interval.begin(), interval.end());
        for(int i = 1; i < interval.size(); i++){
            if(interval[i][0] <= interval[i-1][1]){
                interval[i-1][1] = max(interval[i][1], interval[i-1][1]);
                interval.erase(interval.begin()+i);
                i--;
            }
        }
        return interval;

    }
    // static bool cmp(vector<int>& a, vector<int>& b){
    //     cout<<a[0]<<" "<<b[0]<<endl;
    //     if(a[0] > b[0]) return false;
    //     else return a[1] < b[1];
    // }
};