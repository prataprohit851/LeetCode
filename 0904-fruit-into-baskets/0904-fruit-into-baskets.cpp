//Flag wala costing n square so replacing it with a unordered map results in big O of n

class Solution {
public:

    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int i = 0, j = 0, res = 0;
        while(j < fruits.size())
        {
            mpp[fruits[j]]++;
            if(mpp.size() <= 2) res = max(res, j-i+1);
            else
            {
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return res; 
    }
};



// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int i = 0;
//         int j = 1;
//         vector<int> HT (fruits.size(), 0);
//         int ans = INT_MIN;
//         int flag = 0;
//         HT[fruits[0]]++;
//         while(j < fruits.size()+1){
//             flag = 0;
//             for(int check = 0; check < fruits.size(); check++){
//                 cout<<HT[check]<<" ";
//                 if(HT[check] != 0){
//                     flag++;
//                 }
//             }
//             cout<<"--->"<<i<<" "<<j<<endl;
//             if(flag <= 2) ans = max(ans, j-i);
//             if(flag <= 2){
//                 if(j < fruits.size()) HT[fruits[j]]++;
//                 // HT[fruits[j]]++;
//                 j++;
//             }
//             else{
//                 if(i < fruits.size()) HT[fruits[i]]--;
//                 // HT[fruits[i]]--;
//                 i++;
//             }
//         }
//         return ans;
//     }
// };