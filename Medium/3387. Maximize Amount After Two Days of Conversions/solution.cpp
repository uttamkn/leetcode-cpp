#include "../../macros.h"

class Solution {
public:
  double maxAmount(string initialCurrency, vector<vector<string>> &pairs1,
                   vector<double> &rates1, vector<vector<string>> &pairs2,
                   vector<double> &rates2) {

    umap<string, umap<string, double>> map1;
    umap<string, bool> visited1;
    make_graph(map1, visited1, pairs1, rates1);

    umap<string, double> day1_res;
    dfs_day1(map1, visited1, 1, day1_res, initialCurrency);
    for (const auto &[key, val] : day1_res) {
      cout << key << " " << val << endl;
    }

    umap<string, umap<string, double>> map2;
    umap<string, bool> visited2;
    make_graph(map2, visited2, pairs2, rates2);

    double max_amt = 1;
    for (const auto &[key, val] : day1_res) {
      double day2_res = 0;
      dfs_day2(map2, visited2, val, day2_res, key, initialCurrency);
      max_amt = max(day2_res, max_amt);
      visited2.clear();
    }

    return max_amt;
  }

private:
  void make_graph(umap<string, umap<string, double>> &map,
                  umap<string, bool> &visited, vector<vector<string>> &pairs,
                  vector<double> &rates) {
    rep(i, 0, sz(pairs)) {
      map[pairs[i][0]][pairs[i][1]] = rates[i];
      map[pairs[i][1]][pairs[i][0]] = double(1.0 / rates[i]);

      visited[pairs[i][0]] = false;
      visited[pairs[i][1]] = false;
    }
  }

  void print_graph(umap<string, umap<string, double>> &map) {
    for (const auto &[key, val] : map) {
      cout << key << " -> ";
      for (const auto &[k, v] : val) {
        cout << k << " " << v << ", ";
      }
      cout << endl;
    }
  }

  void dfs_day1(umap<string, umap<string, double>> &map,
                umap<string, bool> &visited, double currency_val,
                umap<string, double> &res, string currency) {

    visited[currency] = true;
    res[currency] = currency_val;
    for (const auto &[key, val] : map[currency]) {
      if (!visited[key]) {
        dfs_day1(map, visited, currency_val * double(val), res, key);
      }
    }
  }

  void dfs_day2(umap<string, umap<string, double>> &map,
                umap<string, bool> &visited, double currency_val, double &res,
                string currency, string initialCurrency) {
    visited[currency] = true;
    if (currency == initialCurrency) {
      res = currency_val;
      return;
    }
    for (const auto &[key, val] : map[currency]) {
      if (!visited[key]) {
        dfs_day2(map, visited, currency_val * double(val), res, key,
                 initialCurrency);
      }
    }
  }
};

int main() {
  fast_io;
  Solution s;
  string initialCurrency = "A";
  vector<vector<string>> pairs1 = {{"A", "P"}, {"A", "O"}};
  vector<double> rates1 = {7.7, 3.9};
  vector<vector<string>> pairs2 = {{"O", "A"}, {"A", "P"}};
  vector<double> rates2 = {7.2, 7.7};

  cout << s.maxAmount(initialCurrency, pairs1, rates1, pairs2, rates2) << endl;
  return 0;
}
