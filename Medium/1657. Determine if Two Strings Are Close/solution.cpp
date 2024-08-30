class Solution {
public:
  bool closeStrings(string word1, string word2) {
    const int n1 = word1.length(), n2 = word2.length();
    if (n1 != n2)
      return false;

    unordered_map<char, int> w1, w2;
    for (int i = 0; i < n1; ++i) {
      w1[word1[i]]++;
      w2[word2[i]]++;
    }
    for (auto it = w1.begin(); it != w1.end(); ++it) {
      const char curr_char = it->first;
      if (w2.find(curr_char) == w2.end())
        return false;

      const int curr_size = w1.at(curr_char);
      auto it2 = w2.begin();
      for (; it2 != w2.end(); ++it2) {
        if (it2->second == curr_size) {
          it2->second = -1;
          break;
        }
      }
      if (it2 == w2.end())
        return false;
    }
    return true;
  }
};
