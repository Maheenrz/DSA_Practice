class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Using Floyd's Tortoise and Hare (Cycle Detection) algorithm
        int slow = 0;
        int fast = 0;

        // Phase 1: Finding the intersection point
        // The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast)
                break;
        }

        // Phase 2: Finding the entrance to the cycle
        // Reset one pointer to the start and move both pointers one step at a time.
        int finder = 0;
        while (true) {
            finder = nums[finder];
            slow = nums[slow];

            if (slow == finder)
                break;
        }

        return slow;
    }
};