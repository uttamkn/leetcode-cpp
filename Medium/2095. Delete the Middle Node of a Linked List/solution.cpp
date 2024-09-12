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
  ListNode *deleteMiddle(ListNode *head) {
    if (head->next == nullptr)
      return nullptr;

    ListNode *slow = head, *fast = head, *prev = nullptr;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      prev = slow;
      slow = slow->next;
    }

    if (fast->next == nullptr) {
      prev->next = slow->next;
      delete slow;
    } else {
      ListNode *temp = slow->next;
      slow->next = slow->next->next;
      delete temp;
    }

    return head;
  }
};
int main() {
  Solution sol;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  ListNode *result = sol.deleteMiddle(head);
  while (result != nullptr) {
    cout << result->val << " ";
    result = result->next;
  }
  return 0;
}
