#include "../macros.h"
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;

    int n = s.size();
    int longest_substr = 0, front = 0;

    for (int back = 0; back < n; ++back) {
      // If the character is already in the map and its index is greater than or
      // equal to front, move front to the next index of the character.
      if (map.find(s[back]) != map.end() && map[s[back]] >= front) {
        front = map[s[back]] + 1;
      }
      map[s[back]] = back;
      longest_substr = max(longest_substr, back - front + 1);
    }

    return longest_substr;
  }
};

int main() {
  Solution solution;
  return 0;
}
