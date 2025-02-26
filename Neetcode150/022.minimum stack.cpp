#include "../macros.h"
using namespace std;

class MinStack {
  stack<pair<int, int>> stk;
  int min_val;

public:
  MinStack() : min_val(INT_MAX) {}

  void push(int val) {
    if (val < min_val)
      min_val = val;

    stk.push({val, min_val});
  }

  void pop() {
    stk.pop();
    if(stk.empty())
      min_val = INT_MAX;
    else
      min_val = stk.top().second;
  }

  int top() { return stk.top().first; }

  int getMin() { return stk.top().second; }
};

int main() {
  MinStack minStack;
  return 0;
}
