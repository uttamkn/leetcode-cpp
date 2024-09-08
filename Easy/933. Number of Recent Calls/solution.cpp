#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
  int count;
  queue<int> q;
  int range;

public:
  RecentCounter() { count = 0; }

  int ping(int t) {
    q.push(t);
    count++;
    while (q.front() < t - 3000) {
      q.pop();
      count--;
    }
    return count;
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
  RecentCounter rc;
  vector<int> t = {1, 100, 3001, 3002};
  if (rc.ping(t[0]) == 1 && rc.ping(t[1]) == 2 && rc.ping(t[2]) == 3 &&
      rc.ping(t[3]) == 3)
    cout << "test case passed" << endl;
  else
    cout << "Test case failed" << endl;
  return 0;
}
