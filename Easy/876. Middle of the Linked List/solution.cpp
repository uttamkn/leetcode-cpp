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
    ListNode* middleNode(ListNode* head) {
        ListNode *tortoise=head, *rabbit=head;
        while((rabbit->next!=nullptr) && (rabbit->next->next!=nullptr)) {
            tortoise=tortoise->next;
            rabbit=rabbit->next->next;
        }

        if(rabbit->next==nullptr) return tortoise;
        
        if(rabbit->next->next==nullptr) return tortoise->next;

        return tortoise;
    }
};