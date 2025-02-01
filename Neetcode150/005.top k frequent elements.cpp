#include "../macros.h"

class QuickSort {
public:
  void swap(vi &vec, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
  }

  int partition(vi &vec, int s, int e) {
    int pivot = vec[e];
    int i = s;
    rep(j, s, e) {
      if (vec[j] < pivot) {
        swap(vec, i, j);
        i++;
      }
    }
    swap(vec, i, e);

    return i;
  }

  void quickSort(vi &vec, int s, int e) {
    if (s < e) {
      int pivot = partition(vec, s, e);

      quickSort(vec, s, pivot - 1);
      quickSort(vec, pivot + 1, e);
    }
  }
};

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    umap<int, int> freq;
    priority_queue<pair<int, int>> pq;

    for (int num : nums) {
      freq[num]++;
    }

    for (const auto &[key, val] : freq) {
      pq.push({val, key});
    }

    vi res;
    rep(i, 0, k) {
      res.push_back(pq.top().second);
      pq.pop();
    }

    return res;
  }

private:
  void swap(vi &vec, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
  }
};

int main() {

  // QuickSort qs;
  // vi vec = {3, 0, 1, 0};
  // dbg_vec(vec);
  // qs.quickSort(vec, 0, vec.size() - 1);
  // dbg_vec(vec);

  Solution sol;
  vi nums = {1};
  int k = 1;
  vi res = sol.topKFrequent(nums, k);
  dbg_vec(res);

  return 0;
}
