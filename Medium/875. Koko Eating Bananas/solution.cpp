#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int maxK = *max_element(piles.begin(), piles.end());
    int low = 0, high = maxK - 1, mid;
    while (low <= high) {
      mid = low + (high - low) / 2;
      cout << "low: " << low << " high: " << high << " mid: " << mid << endl;
      if (isEnough(piles, mid + 1, h)) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return (isEnough(piles, mid + 1, h)) ? mid + 1 : mid + 2;
  }

private:
  bool isEnough(vector<int> &piles, int k, int maxH) {
    int hrs = 0;
    for (int pile : piles) {
      hrs += (pile + (k - 1)) / k;
      if (hrs > maxH)
        return false;
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<int> piles = {30, 11, 23, 4, 20};
  int h = 6;
  if (sol.minEatingSpeed(piles, h) == 23) {
    cout << "Test case passed!" << endl;
  } else {
    cout << "Test case failed!" << endl;
  }
  return 0;
}
