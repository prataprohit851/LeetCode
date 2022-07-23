class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        long min = 1;
        long max = *max_element(p.begin(), p.end());
        
        while(min <= max){
            long mid = min + (max - min) / 2;
            long hours = 0;
            for(auto ele : p){
                hours += ele / mid;
                if(ele % mid != 0) hours++;
            }
            if(hours <= h) max = mid-1;
            else min = mid + 1;
        }
        return min;
    }
};