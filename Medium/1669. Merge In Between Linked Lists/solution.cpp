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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *a_ptr, *b_ptr, *prev_a=list1, *temp_ptr=list1->next;
        int cur_pos=1;
        while(temp_ptr!=nullptr) {
            if(cur_pos==a) a_ptr=temp_ptr;
            if(cur_pos==b) {
                b_ptr=temp_ptr->next;
                break;
            }
            if(cur_pos<a) prev_a=temp_ptr;
            temp_ptr=temp_ptr->next;
            cur_pos++;
        }

        delete a_ptr;
        prev_a->next=list2;
        temp_ptr=list2;
        while(temp_ptr->next!=nullptr) temp_ptr=temp_ptr->next;

        temp_ptr->next=b_ptr;

        return list1;
    }
};