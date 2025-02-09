#include "../macros.h"
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    int n = s.size(), m = t.size();
    if (m > n)
      return "";

    unordered_map<char, int> t_map, wind_map;
    for (int i = 0; i < m; ++i) {
      t_map[t[i]]++;
      wind_map[s[i]]++;
    }

    int matches = 0;
    for (const auto &[key, val] : t_map) {
      if (wind_map.find(key) != wind_map.end()) {
        matches += min(val, wind_map[key]);
      }
    }

    if (matches == m)
      return s.substr(0, m);

    int front = 0;
    int min_win_size = INT_MAX;
    int min_win_start = 0;
    for (int back = m; back < n; back++) {
      if (t_map.find(s[back]) != t_map.end()) {
        wind_map[s[back]]++;
        if (t_map[s[back]] >= wind_map[s[back]]) {
          matches++;
        }
        while (matches == m) {
          if (t_map.find(s[front]) != t_map.end()) {
            if (min_win_size > back - front + 1) {
              min_win_size = back - front + 1;
              min_win_start = front;
            }

            if (t_map[s[front]] == wind_map[s[front]]) {
              matches--;
            }
            wind_map[s[front]]--;
          }
          front++;
        }
      }
    }
    return (min_win_size == INT_MAX) ? ""
                                     : s.substr(min_win_start, min_win_size);
  }
};

int main() {
  Solution solution;
  return 0;
}
