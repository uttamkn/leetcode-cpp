#include <iostream>
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        struct ListNode *prev=NULL;
        struct ListNode *cur=head;
        while(head->next!=NULL) {
            head=head->next;
            cur->next=prev;
            prev=cur;
            cur=head;
        }
        head->next=prev;

        return head;
    }
};