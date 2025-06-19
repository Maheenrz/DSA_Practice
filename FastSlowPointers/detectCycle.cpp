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
    ListNode* detectCycle(ListNode* head) {
        //if head is NULL or has only one node, there can't be a cycle
        if (head == NULL || head->next == NULL)  return NULL;
        

        //using Floyd's Cycle Detection Algorithm (Tortoise and Hare)
        ListNode* slow = head;
        ListNode* fast = head;

        //move slow pointer by 1 step and fast pointer by 2 steps
        //if they meet, there is a cycle
        //if fast pointer reaches the end, there is no cycle
        while (fast  && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        //now check if slow and fast pointers met
        //if they did, reset slow to head and move both pointers one step at a time
        //the point where they meet again is the start of the cycle
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }

        //if we exit the loop without finding a cycle, return NULL
        return NULL;
    }
};