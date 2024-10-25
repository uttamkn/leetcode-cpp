#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<double>
  calcEquation(std::vector<std::vector<std::string>> &equations,
               std::vector<double> &values,
               std::vector<std::vector<std::string>> &queries) {
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>
        map;
    int n = values.size();
    std::vector<double> results;

    for (int i = 0; i < n; ++i) {
      map[equations[i][0]].push_back(
          (std::pair<std::string, double>){equations[i][1], values[i]});

      map[equations[i][1]].push_back((std::pair<std::string, double>){
          equations[i][0], (double)1.0 / values[i]});
    }

    for (std::vector<std::string> query : queries) {
      double response = -1.0;

      if (map.find(query[0]) != map.end() && map.find(query[1]) != map.end()) {
        std::unordered_map<std::string, bool> visited;
        response = divideUsingDfs(query[0], query[1], map, visited, 1);
      }

      // -1 if any variable is unknown.
      results.push_back(response);
    }

    return results;
  }

private:
  double divideUsingDfs(
      std::string &numerator, std::string &denominator,
      std::unordered_map<std::string,
                         std::vector<std::pair<std::string, double>>> &map,
      std::unordered_map<std::string, bool> &visited, double accumilatedVal) {

    visited[numerator] = true;

    if (numerator == denominator)
      return accumilatedVal;

    for (auto &[node, val] : map[numerator]) {
      if (visited[node])
        continue;

      double res =
          divideUsingDfs(node, denominator, map, visited, accumilatedVal * val);

      if (res != -1)
        return res;
    }

    return -1;
  }
};

struct Testcase {
  std::vector<std::vector<std::string>> equations;
  std::vector<double> values;
  std::vector<std::vector<std::string>> queries;
  std::vector<double> expected;
};

void printVector(std::vector<double> &v) {
  for (double i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main() {
  Solution solution;
  Testcase testcases[] = {
      {
          {{"a", "b"}, {"b", "c"}},
          {2.0, 3.0},
          {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}},
          {6.0, 0.5, -1.0, 1.0, -1.0},
      },
      {
          {{"a", "b"}, {"b", "c"}, {"bc", "cd"}},
          {1.5, 2.5, 5.0},
          {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}},
          {3.75000, 0.40000, 5.00000, 0.20000},
      },
      {
          {{"x1", "x2"}, {"x2", "x3"}, {"x3", "x4"}, {"x4", "x5"}},
          {3.0, 4.0, 5.0, 6.0},
          {{"x1", "x5"},
           {"x5", "x2"},
           {"x2", "x4"},
           {"x2", "x2"},
           {"x2", "x9"},
           {"x9", "x9"}},
          {360.00000, 0.00833, 20.00000, 1.00000, -1.00000, -1.00000},
      },
  };

  int i = 1;
  for (Testcase &testcase : testcases) {
    std::vector<double> results = solution.calcEquation(
        testcase.equations, testcase.values, testcase.queries);

    if (results == testcase.expected) {
      std::cout << "Testcase " << i << " Passed" << std::endl;
    } else {
      std::cout << "Testcase " << i << " Failed" << std::endl;
      std::cout << "Expected: ";
      printVector(testcase.expected);
      std::cout << "Got     : ";
      printVector(results);
    }
    std::cout << std::endl;
    i++;
  }
  return 0;
}
