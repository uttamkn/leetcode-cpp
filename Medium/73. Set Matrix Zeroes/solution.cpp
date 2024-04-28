class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zero_locs;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j]==0) zero_locs.push_back({i, j});
            }
        }

        for(int i=0; i<zero_locs.size(); i++) {
            setRowColZero(matrix, zero_locs[i]);
        }
    }
private:
    void setRowColZero(vector<vector<int>>& matrix, vector<int> pos) {
        for(int i=0; i<matrix[0].size(); i++) {
            matrix[pos[0]][i]=0;
        }

        for(int i=0; i<matrix.size(); i++) {
            matrix[i][pos[1]]=0;
        }
    }
};