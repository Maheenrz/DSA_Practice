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
        // Handle base cases: empty list or single node list with n = 1
        if ((head == NULL) || (head->next == NULL && n == 1))
            return NULL;

        // Initialize two pointers
        ListNode* fast = head;
        ListNode* slow = head;

        // Move 'fast' n steps ahead
        while (n--) {
            fast = fast->next;
        }

        // If 'fast' is null after n steps, we are deleting the head node
        if (fast == NULL) {
            ListNode* temp = head;
            head = head->next; // Move head forward
            delete temp;       // Free memory
            return head;
        }

        // Move both pointers until 'fast' reaches the end
        // 'slow' will point to the node before the one to delete
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the target node (nth from the end)
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head; 
    }
};
