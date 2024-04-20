class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int diagSum=0;
        for(int i=0; i<mat.size(); i++) {
            diagSum+=mat[i][i];
        }
        
        for(int i=0, j=mat.size()-1; i<mat.size(); i++) {
            diagSum+=mat[i][j];
            j--;
        }

        if(mat.size()%2!=0) {
            int mid = mat.size()/2;
            diagSum-=mat[mid][mid];
        }

        return diagSum;
    }
};