#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int pairSum(ListNode *head) {
    ListNode *cur = head;
    vector<ListNode *> list;
    while (cur) {
      list.push_back(cur);
      cur = cur->next;
    }
    int n = list.size();
    int max = INT_MIN;

    for (int i = 0; i < (n / 2); ++i) {
      int sum = list[i]->val + list[n - 1 - i]->val;
      max = (max > (sum)) ? max : (sum);
    }

    return max;
  }
};

int main() {
  Solution sol;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  cout << sol.pairSum(head) << endl;

  return 0;
}
