#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> freq, freq_of_freqs;

    for (int a : arr) {
      freq[a]++;
    }

    for (auto &[key, val] : freq) {
      freq_of_freqs[val]++;
    }

    for (auto &[key, val] : freq_of_freqs) {
      if (val > 1)
        return false;
    }

    return true;
  }
};

int main() {
  Solution sol;
  vector<int> tests[] = {
      {1, 2, 2, 1, 1, 3},
      {1, 2},
      {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0},
  };
  for (auto &test : tests) {
    cout << sol.uniqueOccurrences(test) << endl;
  }
  return 0;
}
