
#include <unordered_map>
using namespace std;
class Solution {
  unordered_map<int, int> map;

public:
  int tribonacci(int n) {
    if (n == 0)
      return 0;
    if (n < 3)
      return 1;

    if (map.find(n) == map.end()) {
      map[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }

    return map[n];
  }
};
