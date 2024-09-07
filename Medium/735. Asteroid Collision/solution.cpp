#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    auto it = asteroids.end() - 1;
    while (it > asteroids.begin()) {
      int asteroid1 = *it, asteroid2 = *(it - 1);
      // If both asteroids are moving in the same direction, then no collision
      // or if both are moving away from each other then also no collision
      if ((asteroid1 * asteroid2) > 0 || (asteroid2 < 0 && asteroid1 > 0)) {
        it--;
        continue;
      } else if (abs(asteroid1) == abs(asteroid2)) {
        asteroids.erase(it - 1, it + 1);
      } else {
        (abs(asteroid1) > abs(asteroid2)) ? asteroids.erase(it - 1)
                                          : asteroids.erase(it);
      }

      it = asteroids.end() - 1;
    }

    return asteroids;
  }
};

int main() {
  Solution sol;
  vector<int> asteroids[] = {{5, 10, -5}, {8, -8}, {10, 2, -5}, {-2, -1, 1, 2}};
  for (auto &asteroid : asteroids) {
    vector<int> result = sol.asteroidCollision(asteroid);
    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
