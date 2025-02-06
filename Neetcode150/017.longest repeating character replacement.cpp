#include "../macros.h"
using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.size(), front = 0;
    unordered_map<char, int> char_freq;
    int res = 0;

    for (int back = 0; back < n; back++) {
      char_freq[s[back]]++;

      // window size - freq of most freq char = number of characters that has to
      // be replaced in the window
      //  If the window size - the frequency of the most frequent character is
      //  greater than k then we need to shrink the window
      int cur_max_freq = max_element(char_freq.begin(), char_freq.end(),
                                     [](const auto &a, const auto &b) {
                                       return a.second < b.second;
                                     })
                             ->second;

      while (back - front + 1 - cur_max_freq > k) {
        char_freq[s[front]]--;
        front++;
        if (char_freq.empty())
          cur_max_freq = 0;
        else
          cur_max_freq = max_element(char_freq.begin(), char_freq.end(),
                                     [](const auto &a, const auto &b) {
                                       return a.second < b.second;
                                     })
                             ->second;
      }

      res = max(res, back - front + 1);
    }

    return res;
  }
};

int main() {
  Solution solution;
  return 0;
}
