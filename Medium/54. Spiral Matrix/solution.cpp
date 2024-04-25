class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral_order;
        int right=matrix[0].size()-1, bottom=matrix.size()-1, left=0, top=1;  //right-> number of columns   left-> number of rows
        int numOfEle = matrix.size()*matrix[0].size();
        while(spiral_order.size()<numOfEle) {
            for(int i=left; i<=right; i++) {
                spiral_order.push_back(matrix[left][i]);
            }

            if(spiral_order.size()==numOfEle) break;

            for(int i=top; i<=bottom; i++) {
                spiral_order.push_back(matrix[i][right]);
            }
            right--;    
            
            if(spiral_order.size()==numOfEle) break;

            for(int i=right; i>=left; i--) {
                spiral_order.push_back(matrix[bottom][i]);
            }
            bottom--;   

            if(spiral_order.size()==numOfEle) break;

            for(int i=bottom; i>=top; i--) {
                spiral_order.push_back(matrix[i][left]);
            }
            left++;
            top++;
        }

        return spiral_order;
    }
};