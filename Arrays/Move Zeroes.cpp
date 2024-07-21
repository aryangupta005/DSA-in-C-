class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        
        // Find the first zero in the array
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                j = i;
                break;
            }
        }
        // If no zero is found, return early as no changes are needed
        if (j == -1) return;

        // Move non-zero elements to the position of the first zero found
        for(int i = j + 1; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
