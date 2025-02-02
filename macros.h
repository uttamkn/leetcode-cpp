#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg_vec(v) cerr << #v << " = "; for (auto x : v) cerr << x << " "; cerr << endl;
#define dbg_pair(p) cerr << #p << " = {" << p.first << ", " << p.second << "}" << endl;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()


#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) / gcd(a, b) * (b))
#define ceil(a, b) ((a + b - 1) / b)

#define sz(x) (int)(x).size() 
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define umap unordered_map
#define uset unordered_set

#define imin INT_MIN
#define imax INT_MAX
#define bankai cout << "Katen Kyokotsu Karamatsu Shinjuu" << endl;

struct vectorHash {
  size_t operator()(const vector<int> &v) const {
    hash<int> int_hash;
    size_t seed = v.size();
    for (int i : v) {
      seed ^= int_hash(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

