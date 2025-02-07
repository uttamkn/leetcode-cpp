#include "../macros.h"
using namespace std;

// O(n * m)
// class Solution {
// public:
//   bool checkInclusion(string s1, string s2) {
//     int n = s2.size(), m = s1.size();
//     if (m > n)
//       return false;
//     unordered_map<char, int> hm;
//
//     for (const char c : s1) {
//       hm[c]++;
//     }
//
//     int j;
//     for (int i = 0; i < n; ++i) {
//       if (hm.find(s2[i]) != hm.end()) {
//         j = i;
//         unordered_map<char, int> temp_hm = hm;
//
//         while (j < n && temp_hm.find(s2[j]) != temp_hm.end()) {
//           temp_hm[s2[j]]--;
//           if (temp_hm[s2[j]] == 0)
//             temp_hm.erase(s2[j]);
//           j++;
//         }
//
//         if (temp_hm.empty())
//           return true;
//         else
//           i = j + 1;
//       }
//     }
//
//     return false;
//   }
// };

// better solution O(26 * s2 size)
// class Solution {
// public:
//   bool checkInclusion(string s1, string s2) {
//     int n = s1.size(), m = s2.size();
//
//     if (n > m)
//       return false;
//
//     array<int, 26> hm1, window_hm;
//
//     for (const char c : s1) {
//       hm1[c - 'a']++;
//     }
//
//     // fixed size sliding window of the size n
//     for (int i = 0; i < m; ++i) {
//       window_hm[s2[i] - 'a']++;
//       if (i + 1 >= n) {
//         if (hm1 == window_hm)
//           return true;
//
//         window_hm[s2[i + 1 - n] - 'a']--;
//       }
//     }
//
//     return false;
//   }
// };

// even better O(26) + O(s2 size)
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    if (n > m)
      return false;

    array<int, 26> hm1, hm2;

    for (int i = 0; i < n; ++i) {
      hm1[s1[i] - 'a']++;
      hm2[s2[i] - 'a']++;
    }

    int matches = 0;
    for (int i = 0; i < 26; ++i) {
      if (hm1[i] == hm2[i])
        matches++;
    }

    // matches will represent the number of characters that are equal between
    // hm1(s1) and hm2(window)
    for (int j = n; j < m; ++j) {
      if (matches == 26)
        return true;

      int first_index = s2[j - n] - 'a';
      int last_index = s2[j] - 'a';

      hm2[last_index]++;
      if (hm1[last_index] == hm2[last_index]) {
        matches++;
      } else if (hm1[last_index] == hm2[last_index] - 1) { // if it was equal before you added the new char to the window dec matches
        matches--;
      }

      hm2[first_index]--;
      if (hm1[first_index] == hm2[first_index]) {
        matches++;
      } else if (hm1[first_index] == hm2[first_index] + 1) { // if it was equal before you removed the first char in the window dec matches
        matches--;
      }
    }

    return matches == 26;
  }
};

int main() {
  Solution solution;
  return 0;
}
