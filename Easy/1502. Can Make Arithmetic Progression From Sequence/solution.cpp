class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int diff=arr[1]-arr[0];
        for(int i=0; i<arr.size(); i++){
            if(arr[i]!=(arr[0]+(i*diff))) return false; 
        }

        return true;
    }
};