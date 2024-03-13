class Solution {
public:
    int pivotInteger(int n) {
        int total_sum=(n*(n+1))/2;
        int temp_sum=0;
        for(int i=1; i<=n; i++) {
            temp_sum+=i;
            if(temp_sum==(total_sum-temp_sum+i)) return i;
        }    

        return -1;
    }
};