class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        float slope, cur_slope;
        if(coordinates[0][0]-coordinates[1][0]==0) slope=INT_MAX;
        else slope=(coordinates[0][1]-coordinates[1][1]) / (float)(coordinates[0][0]-coordinates[1][0]);
        for(int i=1; i<coordinates.size(); i++) {
            if(coordinates[0][0]-coordinates[i][0]==0) cur_slope=INT_MAX;
            else cur_slope=(coordinates[0][1]-coordinates[i][1]) / (float)(coordinates[0][0]-coordinates[i][0]);
            if(slope!=cur_slope) return false; 
        }
        return true;
    }
};