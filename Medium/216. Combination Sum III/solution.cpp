#include <bits/stdc++.h>

class Solution {
public:
  std::vector<std::vector<int>> combinationSum3(int k, int n) {
    if (k >= n)
      return {};

    std::vector<int> cur_comb;
    std::vector<std::vector<int>> ans;
    int i = 1;

    solve(cur_comb, ans, i, k, n);
    return ans;
  }

private:
  void solve(std::vector<int> &cur_comb, std::vector<std::vector<int>> &ans,
             int i, int k, int n) {
    // for (int x : cur_comb) {
    //   std::cout << x << " ";
    // }
    // std::cout << std::endl;
    if (cur_comb.size() == k) {
      if (std::accumulate(cur_comb.begin(), cur_comb.end(), 0) == n) {
        ans.push_back(cur_comb);
      }
      return;
    }

    for (int j = i; j <= 9; j++) {
      cur_comb.push_back(j);
      solve(cur_comb, ans, j + 1, k, n);
      cur_comb.pop_back();
    }
  }
};

int main() {
  Solution solution;
  std::vector<std::vector<int>> output = solution.combinationSum3(3, 7);

  std::cout << "Output: " << std::endl;
  for (std::vector<int> v : output) {
    for (int x : v) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
