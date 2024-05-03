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

bool customCompare(ListNode* a, ListNode* b) {
        return a->val < b->val;
    }

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        ListNode* cur1=list1;
        ListNode* cur2=list2;
        vector<ListNode*> sorted;
        while(cur1) {
            sorted.push_back(cur1);
            cur1=cur1->next;
        }

        while(cur2) {
            sorted.push_back(cur2);
            cur2=cur2->next;
        }

        sort(sorted.begin(), sorted.end(), customCompare);
        int i;
        for(i=0; i<sorted.size()-1; i++) {
            sorted[i]->next=sorted[i+1];
        }
        sorted[i]->next=nullptr;

        return sorted[0];
    }
};