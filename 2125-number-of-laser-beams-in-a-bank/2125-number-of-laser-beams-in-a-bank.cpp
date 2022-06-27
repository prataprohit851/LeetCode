class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevCamCount = 0;
        int cameraCount = 0;
        int beams = 0;
        for(int i = 0; i < bank.size(); i++){
            for(int j = 0; j < bank[0].size(); j++){
                if(bank[i][j] == '1') cameraCount++;
            }
            cout<<cameraCount;
            if(cameraCount){
                beams = beams+prevCamCount*cameraCount;
                prevCamCount = cameraCount;
            }
            cameraCount = 0;
        }
        return beams;
    }
};