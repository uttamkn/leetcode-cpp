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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur=head, *prev=NULL, *temp=head;

        if(head->next==NULL) {
            delete head;
            head=NULL;
            return head;
        }

        while(cur->next!=NULL) {
            temp=cur;
            for(int i=0; i<n-1; i++) {
                temp=temp->next;
            }

            if(temp->next==NULL) break;

            prev=cur;
            cur=cur->next;
        }

        if(prev==NULL) {
            temp = head;
            head=head->next;
            delete temp;
            temp=NULL;
            return head;
        }

        prev->next=cur->next;
        delete cur;
        cur=NULL;

        return head;
    }
};