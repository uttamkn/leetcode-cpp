#include "../macros.h"
using namespace std;

class Solution {
public:
  // replace "#" with "\#" and "\" with "\\" and use "#" as the delimiter
  string encode(vector<string> &strs) {
    string encoded = "";

    for(string str: strs) {
      for(char c : str) {
        if(c == '#') {
          encoded += '\\';
        }

        if (c =='\\') {
          encoded += '\\';
        }
        encoded += c;
      }
      encoded += '#';
    }
    return encoded;
  }

  vector<string> decode(string s) {
    vector <string> decoded;
    string cur_string = "";

    rep(i, 0, sz(s)) {
      if(s[i] == '\\') {
        cur_string += s[++i];
        continue;
      }
      if(s[i] == '#') {
        decoded.push_back(cur_string);
        cur_string = "";
        continue;
      }
      cur_string += s[i];
    }
    return decoded;
  }
};

int main() {
  Solution solution;
  vector<vector<string>> test = {
    {"hello", "world"},
    {"hel#lo", "worl##d", "#hello", "world"},
    {"hel\\lo", "world", "hel\\#lo", "world\\", "#\\hello", "\\#world"},
  };

  for (auto t : test) {
    vector<string> original = t;
    string encoded = solution.encode(t);
    dbg(encoded)
    vector<string> decoded = solution.decode(encoded);
    dbg_vec(decoded)
    if (original == decoded) {
      dbg("Test passed!")
    } else {
      dbg("Test failed!")
    }
  }

  return 0;
}
