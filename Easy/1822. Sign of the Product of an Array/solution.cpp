class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg=0;
        for(int num : nums) {
            if(num==0) return 0;
            if(num<0) neg++;
        }

        return signFunc(neg);
    }
private:
    int signFunc(int num) {
        if(num%2==0) return 1;
        else return -1;
    }
};