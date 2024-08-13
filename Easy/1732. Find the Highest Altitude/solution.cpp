class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int prefix_sum = 0;
    int max_val = 0;

    for (int i = 0; i < gain.size(); ++i) {
      prefix_sum += gain[i]; // current altitude
      max_val = max(prefix_sum, max_val);
    }

    return max_val;
  }
};
