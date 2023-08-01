class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = 0;

        for(int index = 0; index < nums.size(); index++){
            //cout<<index<<endl;
            if(nums[index] == 2){
                nums[k++] = 2;
            }
            else if(nums[index] == 1){
                nums[k++] = 2;
                nums[j++] = 1;
            }
            else{
                nums[k++] = 2;
                nums[j++] = 1;
                nums[i++] = 0;
            }
        }
    }
};