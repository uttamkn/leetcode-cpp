#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    sort(potions.begin(), potions.end());
    int n = potions.size();
    vector<int> succPairs;
    for (int spell : spells) {
      int low = 0, high = n - 1;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        // math trick to do ceil(success / potions[mid]) without floating point
        // operations
        if (spell >= ((success + potions[mid] - 1) / potions[mid])) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      succPairs.push_back(n - low);
    }
    return succPairs;
  }
};

int main() {
  Solution sol;
  vector<int> spells = {1, 2, 3};
  vector<int> potions = {1, 2, 3, 4, 5};
  long long success = 10;
  vector<int> res = sol.successfulPairs(spells, potions, success);
  for (int i : res) {
    cout << i << " ";
  }
  return 0;
}
