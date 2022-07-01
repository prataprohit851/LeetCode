class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int i = 0, units = 0, currBox = 0;
        while(currBox != truckSize && i < boxTypes.size()){
            if(boxTypes[i][0] > truckSize-currBox){
                units += (truckSize-currBox)*boxTypes[i][1];
                return units;
            }
            else{
                currBox += boxTypes[i][0];
                units += boxTypes[i][0]*boxTypes[i][1];
            }
            i++;
        }
        return units;
    }
    static bool comp(vector<int>& a, vector<int> b){
        return a[1] > b[1];
    }
};