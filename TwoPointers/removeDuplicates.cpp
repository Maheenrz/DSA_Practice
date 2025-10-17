class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int a = 0;
        for (int b = 1; b < nums.size(); b++) {
            if (nums[a] != nums[b]) {
                a++;
                nums[a]=nums[b];
            }
        }
        return a+1;
    }
};