class Solution {
public:
    double average(vector<int>& salary) {
        int mi = INT_MAX;
        int ma = INT_MIN;
        int count = 0;
        
        for(auto x : salary){
            mi = min(mi, x);
            ma = max(ma, x);
            count += x;
        }
        return (count-mi-ma)/(salary.size()-2.00);
    }
};