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
        if(!head || head->next==NULL){
            return false;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        // floyd's cycle detection
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            // if slow and fast meet , there is a cycle
            if(slow==fast){
                return true;
            }
        }

        return false;
    
    }
};