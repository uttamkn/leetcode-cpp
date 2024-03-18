class Solution {
public:
    static bool comparePairs(const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), comparePairs);
        int arrow_count=1,j=0;
        for(int i=1; i<points.size(); i++) {
            if(points[j][1]<points[i][0]) {
                arrow_count++;
                j=i;
            }
            else {
                if (points[j][1]>points[i][1]) j=i;
            }
        }

        return arrow_count;
    }
};