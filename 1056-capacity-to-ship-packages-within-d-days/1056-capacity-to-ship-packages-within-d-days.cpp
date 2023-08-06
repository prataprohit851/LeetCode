class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        // cout<<"low: "<<low<<endl;
        // cout<<"high: "<<high<<endl;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int day = 1;
            int weight = 0;
            for(auto x : weights){
                weight += x;
                if(weight > mid){
                    weight = x;
                    day++;
                }
            }
            // cout<<day<<endl;
            if(day > days){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};