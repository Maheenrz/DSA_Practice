class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indices;
        int i = 0;
        int j = numbers.size()-1;

        while(1){
            if(numbers[i] + numbers[j] == target){
                indices.push_back(i+1);
                indices.push_back(j+1);
                break;
            }
            else if(numbers[i] + numbers[j] > target){
                j--;
            }
            else{
                i++;
            }
        }
        return indices;
    }
};