#include "../macros.h"
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      umap<int, bool> m;

      rep(i, 0, sz(nums)) {
      if(m.find(nums[i]) == m.end()) {
        m[nums[i]] = true;
      } else {
        return true;
      }
    }

    return false;
    }
};

int main() {
  Solution solution;
  return 0;
}
