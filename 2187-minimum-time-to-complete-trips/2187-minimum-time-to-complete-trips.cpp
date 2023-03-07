class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());

        long long tMin = 0;
        long long tMax = 1LL*time[time.size()-1]*totalTrips;
        long long minTime = 1LL*time[time.size()-1]*totalTrips;

        while(tMin <= tMax){
            long long mid = tMax + (tMin-tMax)/2;
            long long t = 0;
            for(int i = 0; i < time.size(); i++){
                t += (mid/time[i]);
            }
            if(t >= totalTrips){
                tMax = mid-1;
                minTime = min(minTime, mid);
            }
            else {
                tMin = mid+1;
            }
        }
        return minTime;
    }
};







// class Solution {
// public:
//     long long minimumTime(vector<int>& time, int totalTrips) {
//         long long t = 1;
//         int currTrips = 0;
//         while(currTrips < totalTrips){
//             for(int i = 0; i < time.size(); i++){
//                 if(t % time[i] == 0) currTrips++;
//             }
//             t++;
//         }
//         return t-1;
//     }
// };

// class Solution {
// public:
//     long long minimumTime(vector<int>& time, int totalTrips) {
//         long long t = 1;
//         vector<int> arr(time.size(), 0);
//         while(accumulate(arr.begin(), arr.end(), 0) < totalTrips){
//             for(int i = 0; i < time.size(); i++){
//                 if(t % time[i] == 0) arr[i]++;
//             }
//             t++;
//         }
//         return t-1;
//     }
// };