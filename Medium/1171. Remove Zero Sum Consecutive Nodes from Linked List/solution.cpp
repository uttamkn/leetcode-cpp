#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int prefix_sum = 0;
        unordered_map<int, ListNode*> prefix_sums;
        prefix_sums[0] = dummy;
        ListNode* current = head;

        while (current) {
            prefix_sum += current->val;
            if (prefix_sums.find(prefix_sum) != prefix_sums.end()) {
                ListNode* to_delete = prefix_sums[prefix_sum]->next;
                int temp_sum = prefix_sum + to_delete->val;
                while (to_delete != current) {
                    prefix_sums.erase(temp_sum);
                    to_delete = to_delete->next;
                    temp_sum += to_delete->val;
                }
                prefix_sums[prefix_sum]->next = current->next;
            } else {
                prefix_sums[prefix_sum] = current;
            }
            current = current->next;
        }

        return dummy->next;
    }
};

int main() {
    Solution ob;
    ListNode* n1 = new ListNode(4);
    ListNode* n2 = new ListNode(-3, n1);
    ListNode* n3 = new ListNode(3, n2);
    ListNode* n4 = new ListNode(2, n3);
    ListNode* n5 = new ListNode(1, n4);

    ListNode* tmp = ob.removeZeroSumSublists(n5);

    while(tmp!=nullptr) {cout << tmp->val << " ";
    cout << endl;
    tmp=tmp->next;
    } 
    return 0;
}