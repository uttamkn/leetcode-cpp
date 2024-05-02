class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        string temp=num1;
        num1=(num1.size()<num2.size())?num2:num1;   
        num2=(num1!=temp)?temp:num2;
        int i=num1.size()-1, j=num2.size()-1;
        string result="0";
        for(int it=j; it>=0; it--) {
            string temp_res=getProduct(num1, (num2[it]-'0'));
            for(int n=0; n<(j-it); n++) {
                temp_res.append("0");
            }
            result=getSum(result, temp_res);
        }
        return result;
    }
private:
    string getProduct(string num1, int n) {
        int carry=0;
        string result="";
        for(int i=num1.size()-1; i>=0; i--){
            int cur_product = (num1[i] - '0')*n;
            result.append(to_string((cur_product+carry)%10));
            carry = (cur_product+carry)/10;
        }
        while(carry){   
            result.append(to_string(carry%10));  
            carry /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string getSum(string num1, string num2) {
        int i = num1.size()-1, j = num2.size()-1;
        int carry = 0;
        string result="";
        while(i>=0 || j>=0){
            int cur_sum = carry;
            if(i>=0) cur_sum += num1[i--]-'0';
            if(j>=0) cur_sum += num2[j--]-'0';
            carry = cur_sum/10;
            result.append(to_string(cur_sum%10));
        }
        while(carry){   
            result.append(to_string(carry%10));   
            carry /= 10;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};