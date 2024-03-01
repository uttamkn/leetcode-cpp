class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int num_of_ones=0;
        string res="";
        for(char bit : s) {
            if(bit == '1') {
                num_of_ones++;
            }
        }

        int i=0;
        while(i<s.size()-1) {
            
            if(num_of_ones!=1) {
                res.append("1");
                num_of_ones--;
            }
            else {
                res.append("0");
            }

            i++;
        }    

        res.append("1");

        return res;
    }
};