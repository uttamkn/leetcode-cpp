class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int i=0, j=0;
        string res="";
        
        while(i<str1.size() && j<str2.size()) {
            if(str1[i]==str2[j]) res+=str1[i];
            i++;
            j++;
        }

    
        while((!res.empty()) && (isNotDivisible(str1, res) || isNotDivisible(str2, res))) {
            res.erase(res.end() - 1);
        }
        
        return res;
    }
private:
    bool isNotDivisible(string str, string sub_string) {
        if(str.find(sub_string, 0)==string::npos) return true;

        for(int i=0; i<str.size(); i+=sub_string.size()) {
            if(str.substr(i, sub_string.size())!=sub_string) return true;
        }

        return false;
    }
};

//one line sol
// class Solution {
// public:
//     string gcdOfStrings(string str1, string str2) {
//         return (str1 + str2 == str2 + str1)? 
//         str1.substr(0, gcd(size(str1),size(str2))): "";
//     }
// };

//proof:
// str1+str2 == str2+str1 if and only if str1 and str2 have a gcd .
// E.g. str1=abcabc, str2=abc, then str1+str2 = abcabcabc = str2+str1
// This(str1+str2==str2+str1) is a requirement for the strings to have a gcd. If one of them is NOT a common part then gcd is "".It means we will return empty string
// Proof:-str1 = mGCD, str2 = nGCD, str1 + str2 = (m + n)GCD = str2 + str1
// Both the strings are made of same substring added multiple times.
// Since they are multiples, next step is simply to find the gcd of the lengths of 2 strings e.g. gcd(6,3) = 3, (we can use gcd function to find that)and get the substring of length 3 from either str1 or str2.
// In c++ it will be str1.substr(0, gcd)