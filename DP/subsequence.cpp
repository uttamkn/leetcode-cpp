#include <bits/stdc++.h>

// find the subsequence of a given array
// each element can be picked or not picked
// Time complexity: O(2^n) there are 2^n possible subsequence of a given array
// https://youtu.be/AxNNVECce8c?si=Ow8yLDIzCvZRJFmr

void print_subseq(int i, const std::vector<int> &vec,
                  std::vector<int> &subseq) {
  if (i >= vec.size()) {
    for (int j = 0; j < subseq.size(); j++) {
      std::cout << subseq[j] << " ";
    }
    std::cout << "\n";
    return;
  }

  // pick
  subseq.push_back(vec[i]);
  print_subseq(i + 1, vec, subseq);

  // not pick
  subseq.pop_back();
  print_subseq(i + 1, vec, subseq);
}

int main() {
  std::vector<int> vec = {3, 1, 2};
  std::vector<int> subseq;
  print_subseq(0, vec, subseq);
  return 0;
}
