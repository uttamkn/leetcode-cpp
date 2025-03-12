#include "../macros.h"
using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> stk;

    for (const string token : tokens) {
      if (token == "+" || token == "-" || token == "/" || token == "*") {
        int b = stk.top();
        stk.pop();
        int a = stk.top();
        stk.pop();

        stk.push(eval(a, b, token[0]));
      } else {
        stk.push(stoi(token));
      }
    }

    return stk.top();
  }

private:
  int eval(int a, int b, char op) {
    switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '/':
      return a / b;
    case '*':
      return a * b;
    }

    return -1;
  }
};

int main() {
  Solution solution;
  return 0;
}
