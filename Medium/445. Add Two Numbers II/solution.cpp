/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> list1, list2;
        ListNode *cur1=l1, *cur2=l2;
        while(cur1) {
            list1.push(cur1);
            cur1=cur1->next;
        }

        while(cur2) {
            list2.push(cur2);
            cur2=cur2->next;
        }

        int carry=0;
        ListNode* prev=nullptr;
        while(!list1.empty() || !list2.empty() || carry) {
            int cur_sum=carry;
            if(!list1.empty()) {
                cur_sum+=list1.top()->val;
                list1.pop();
            }

            if(!list2.empty()) {
                cur_sum+=list2.top()->val;
                list2.pop();
            }
            ListNode* temp = new ListNode(cur_sum % 10);
            temp->next=prev;
            prev=temp;
            carry=cur_sum/10;
        }

        return prev;
    }
};