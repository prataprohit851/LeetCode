class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int x1 = c[0][0];
        int y1 = c[0][1];
        
        int x2 = c[c.size()-1][0];
        int y2 = c[c.size()-1][1];
        
        for(int i = 1; i < c.size()-1; i++){
            if((y1-c[i][1])*(x2-c[i][0]) != (x1-c[i][0])*(y2-c[i][1])) return false;
        }
        return true;
    }
};