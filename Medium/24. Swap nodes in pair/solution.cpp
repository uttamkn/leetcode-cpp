#include <iostream>
#include <stdlib.h>
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
    ListNode* swapPairs(ListNode* head) {

        if(head==NULL || head->next==NULL) {
            return head;
        }

        struct ListNode *prev = head;
        struct ListNode *cur=head->next;
        struct ListNode *newHead = head->next;  //new head

        prev->next=cur->next;   //swap first 2
        cur->next=prev;

        cur=prev->next;
        while(cur!=NULL && cur->next!=NULL ) {
            struct ListNode* temp = cur->next->next;

            prev->next=cur->next;
            cur->next->next=cur;
            cur->next=temp;

            prev=cur;
            cur=temp;
        }

         return newHead;
    }
};
