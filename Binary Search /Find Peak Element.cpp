class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN;
        int x;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= max) {
                max = nums[i];
                x = i;
                
            }
        }
        return x;
    }
};