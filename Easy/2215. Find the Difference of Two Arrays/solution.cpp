class Solution {
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> set1, set2;
    vector<vector<int>> ans(2);

    for (int num : nums1) {
      set1.insert(num);
    }

    for (int num : nums2) {
      set2.insert(num);
    }

    for (auto it = set1.begin(); it != set1.end(); ++it) {
      if (set2.find(*it) == set2.end()) {
        ans[0].push_back(*it);
      }
    }

    for (auto it = set2.begin(); it != set2.end(); ++it) {
      if (set1.find(*it) == set1.end()) {
        ans[1].push_back(*it);
      }
    }

    return ans;
  }
};
