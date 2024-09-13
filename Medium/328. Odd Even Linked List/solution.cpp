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
  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr)
      return head;

    ListNode *even = head, *odd = head->next, *temp = head->next;

    while (odd != nullptr && odd->next != nullptr) {
      cout << "even: " << even->val << " odd: " << odd->val << endl;
      even->next = odd->next;
      even = odd->next;
      odd->next = even->next;
      odd = even->next;
    }

    if (odd != nullptr)
      odd->next = nullptr;

    even->next = temp;

    return head;
  }
};

int main() {
  Solution sol;
  ListNode *head = new ListNode(1);

  ListNode *result = sol.oddEvenList(head);

  while (result != nullptr) {
    cout << result->val << " ";
    result = result->next;
  }
  return 0;
}
