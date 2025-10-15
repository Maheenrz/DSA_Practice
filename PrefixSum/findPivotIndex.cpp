class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum = 0, rightsum = 0,totalsum=0;

        for (int i = 0; i < nums.size(); i++) {
            totalsum+=nums[i];
        }



        for (int i = 0; i < nums.size(); i++) {
            rightsum = totalsum - leftsum - nums[i];
            if(rightsum == leftsum){
                return i;
            }
            leftsum+=nums[i];
        }
        return -1;
    }
};