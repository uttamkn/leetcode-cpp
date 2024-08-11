
class Solution {
public:
  int maxVowels(string s, int k) {
    int cur_num_of_vowels = 0, max_num_of_vowels = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u') {
        cur_num_of_vowels++;
      }

      if (i >= k - 1) {
        max_num_of_vowels = max(max_num_of_vowels, cur_num_of_vowels);
        if (s[i - k + 1] == 'a' || s[i - k + 1] == 'e' || s[i - k + 1] == 'i' ||
            s[i - k + 1] == 'o' || s[i - k + 1] == 'u') {
          cur_num_of_vowels--;
        }
      }
    }

    return max_num_of_vowels;
  }
};
