class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = nums[0], min_so_far = nums[0];
        int maxprod = nums[0], minprod = nums[0];
        int globalmax=nums[0];
        for (int i = 1; i < nums.size(); i++) {
            minprod = min({nums[i], nums[i]*max_so_far, nums[i]*min_so_far});
            maxprod = max({nums[i], nums[i]*max_so_far, nums[i]*min_so_far});

            min_so_far = minprod;
            max_so_far= maxprod;
            globalmax=max(globalmax,max_so_far);
        }

        return globalmax;
    }
};