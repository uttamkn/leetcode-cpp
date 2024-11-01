#include <bits/stdc++.h>
#include <numeric>

class SmallestInfiniteSet {
public:
  std::array<int, 1000> arr;
  SmallestInfiniteSet() { std::iota(arr.begin(), arr.end(), 1); }

  int popSmallest() {
    for (int &num : arr) {
      if (num) {
        int temp = num;
        num = 0;
        return temp;
      }
    }
    return 0;
  }

  void addBack(int num) {
    if (!arr[num - 1])
      arr[num - 1] = num;
  }
};

int main() {
  SmallestInfiniteSet solution;
  return 0;
}
