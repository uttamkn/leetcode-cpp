class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]=(digits[digits.size()-1]+1)%10;
        if(digits[digits.size()-1]!=0) 
        {
            return digits;
        }
        else {
            for(int i=digits.size()-2; i>=0; i--) {
                digits[i]=(digits[i]+1)%10;
                if(digits[i]!=0) break;
            }

            if(digits[0]==0) {
                digits.insert(digits.begin(), 1);
            }
        }
        return digits;
    }
};