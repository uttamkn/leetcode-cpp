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
    bool isPalindrome(ListNode* head) {
        vector<int> num;
        ListNode *cur=head, *prev=nullptr;

        while(cur->next!=nullptr) {
            head=head->next;
            num.push_back(cur->val);
            cur->next=prev;
            prev=cur;
            cur=head;
        }
        num.push_back(cur->val);
        head->next=prev;
        int i=0;
        while(i<num.size()) {
            if(cur->val!=num[i]) return false;
            i++;
            cur=cur->next;
        }

        return true;
    }
};