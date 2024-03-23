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
    void reorderList(ListNode* head) {

        if(head->next==nullptr || head->next->next==nullptr) return;
        ListNode *slow=head, *fast=head;

        //dividing the given list into 2 (A and B)
        while(fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *B=slow->next, *A=head;
        slow->next=nullptr;

        //reversing B
        ListNode *prev=nullptr, *cur=B;
        while(cur->next!=nullptr) {
            B=B->next;
            cur->next=prev;
            prev=cur;
            cur=B;
        }
        B->next=prev;

        //merging A and B
        ListNode *next_to_A, *next_to_B;
        while(B) {
            next_to_A = A->next;
            next_to_B = B->next;

            A->next=B;
            B->next=next_to_A;

            A=next_to_A;
            B=next_to_B;
        }
    }
};