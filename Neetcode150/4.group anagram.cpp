#include "../macros.h"
using namespace std;


class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    umap<string, vector<string>> map;

    for(const string& str: strs) {
      string sortedStr = str;
      sort(all(sortedStr));

      map[sortedStr].push_back(str);
    }

    vector<vector<string>> res;

    for(const auto &[_, val] : map) {
      res.push_back(val);
    }

    return res;
  }
};

int main() {
  Solution solution;
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  solution.groupAnagrams(strs);
  return 0;
}
