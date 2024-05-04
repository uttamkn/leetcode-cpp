/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result=NULL;
    struct ListNode *cur1=l1, *cur2=l2;
    int carry=0;
    while(cur1 || cur2 || carry) {
        int cur_sum=carry;
        if(cur1) {
            cur_sum+=cur1->val;
            cur1=cur1->next;
        }

        if(cur2) {
            cur_sum+=cur2->val;
            cur2=cur2->next;
        }

        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val=cur_sum%10;
        temp->next=NULL;
        carry=cur_sum/10;

        if(result==NULL) {
            result=temp;
            continue;
        }
        struct ListNode* racer = result;
        while(racer->next) racer=racer->next;
        racer->next=temp;
    }

    return result;
}