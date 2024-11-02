#include <bits/stdc++.h>

// Using backtracking
// class Solution {
// public:
//
//     void solve(vector<string> &ans, string output, int i, string digits,
//     string mapping[]){
//         //base case
//         if(i >= digits.length()){
//             ans.push_back(output);
//             return ;
//         }
//
//         int number = digits[i] - '0';                   //2 from "23"
//         string value = mapping[number];                 //"abc"
//
//         for(int k = 0; k < value.length(); k++){
//             output.push_back(value[k]);                 //pushing a from
//             "abc" solve(ans, output, i+1, digits, mapping);   //recursive
//             call for the next number from digits string output.pop_back();
//             //to remove the "a","b","c" through backtracking
//         }
//
//     }
//
//     vector<string> letterCombinations(string digits) {
//         vector<string> ans;
//
//         if(digits.length() == 0){
//             return ans;
//         }
//
//         string output;
//         int i = 0;
//         string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno",
//         "pqrs", "tuv", "wxyz"};
//
//         solve(ans, output, i, digits, mapping);
//         return ans;
//
//     }
// };

class Solution {
  std::unordered_map<std::string, std::vector<std::string>> keypad;

public:
  std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty())
      return {};

    keypad["0"] = {""};
    keypad["1"] = {""};
    keypad["2"] = {"a", "b", "c"};
    keypad["3"] = {"d", "e", "f"};
    keypad["4"] = {"g", "h", "i"};
    keypad["5"] = {"j", "k", "l"};
    keypad["6"] = {"m", "n", "o"};
    keypad["7"] = {"p", "q", "r", "s"};
    keypad["8"] = {"t", "u", "v"};
    keypad["9"] = {"w", "x", "y", "z"};

    int j = 0;
    std::string cur_str = "";
    while (j < digits.size()) {

      std::string temp_str = cur_str + digits[j];

      if (keypad.find(temp_str) == keypad.end()) {
        std::string digit = std::string(1, digits[j]);
        keypad[temp_str] = getCombinations(cur_str, digit);
      }

      cur_str += digits[j];
      j++;
    }

    return keypad[digits];
  }

private:
  std::vector<std::string> getCombinations(const std::string &s1,
                                           const std::string &s2) {

    std::vector<std::string> &letters1 = keypad[s1];
    std::vector<std::string> &letters2 = keypad[s2];

    std::vector<std::string> combinations;

    for (const std::string &c1 : letters1) {
      for (const std::string &c2 : letters2) {
        combinations.push_back(c1 + c2);
      }
    }

    return combinations;
  }
};

int main() {
  Solution solution;
  std::vector<std::string> output = solution.letterCombinations("2345");

  for (std::string s : output) {
    std::cout << s << std::endl;
  }
  return 0;
}
