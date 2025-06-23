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
    bool isPalindrome(ListNode* head) {
        //return true if the list is empty or has only one element
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;

        // traverse slow to the mid of the list
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        // now reverse the remaining list
        ListNode* prev2 = NULL;
        ListNode* next;
        while (slow) {
            next = slow->next;
            slow->next = prev2;
            prev2 = slow;
            slow = next;
        }

        slow = prev2;
        //initializing fast from head in first splitted list
        fast = head;
        //comparing both halves
        //slow is the head of the reversed second half
        while (slow && fast) {
            if (slow->val != fast->val)
            //return false any value does not match
                return false;
            fast = fast->next;
            slow = slow->next;
        }

        return true;
    }
};