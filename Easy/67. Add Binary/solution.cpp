class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1, j=b.size()-1, carry=0, cur_sum;
        string result="";
        while(i>=0 || j>=0 || carry) {
           cur_sum=carry;
           if(i>=0) {
                cur_sum+=a[i]-'0';
                i--;
           }

           if(j>=0) {
                cur_sum+=b[j]-'0';
                j--;
           }

           carry = (cur_sum>1)?1:0;
           result.append(to_string(cur_sum%2));
        }

        reverse(result.begin(), result.end());
        return result;
    }
}; 