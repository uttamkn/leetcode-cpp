#include "../macros.h"
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    string sortS = s;
    string sortT = t;

    sort(all(sortS));
    sort(all(sortT));

    return sortS == sortT;
  }
};

int main() {
  Solution solution;
  return 0;
}
