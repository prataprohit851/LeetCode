class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        if(arr[0] > k) return k;
        int low = 1;
        int high = arr.size()-1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int mnol = arr[mid] - mid - 1;

            
            if(mnol < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        cout<<"low: "<<low<<" "<<"high: "<<high<<endl;

        // if(high == 0){
        //     return k;
        // }
        // else if(low == arr.size()){
        //     return (arr[high]+k-(arr[high]-high-1));
        // }
        // else{
        //     return arr[high]-high+k;
        // }

         
        
        return (arr[high]+k-(arr[high]-high-1));
    }
};