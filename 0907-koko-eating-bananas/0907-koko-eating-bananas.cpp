class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long hours = 0;
            for(auto x : piles){
                hours += ceil(1.0*x/mid);
            }

            if(hours > h){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return low;
    }
};