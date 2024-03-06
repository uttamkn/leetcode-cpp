/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        vector<ListNode*> listOfNodes;
        ListNode *cur=head;
        while(cur->next!=nullptr){             
            if(cur->next==cur) return true; 
            listOfNodes.push_back(cur);
            for(ListNode *node : listOfNodes) {
                if(cur->next==node) return true;
            }
            cur=cur->next;
        }
        return false;         
    }
};