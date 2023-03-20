class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1) return true;
        if(flowerbed.size() == 1 && flowerbed[0] == 1 && n == 0) return true;
        if(flowerbed.size() == 1 && flowerbed[0] == 0 && n == 0) return true;
        if(flowerbed.size() == 1 && flowerbed[0] == 1 && n == 1) return false;
        
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0){
                if(i == 0 && flowerbed[i+1] == 1){
                    continue;
                }
                else if(i == 0 && flowerbed[i+1] == 0){
                    flowerbed[i] = 1;
                    n--;
                }
                else if(i == flowerbed.size()-1 && flowerbed[i-1] == 1){
                    continue;
                }
                else if(i == flowerbed.size()-1 && flowerbed[i-1] == 0){
                    flowerbed[i] = 1;
                    n--;
                }
                else if(flowerbed[i+1] == 0 && flowerbed[i-1] == 0){
                    flowerbed[i] = 1;
                    n--;
                }
                
            }
        }
        return n <=0;
    }
};