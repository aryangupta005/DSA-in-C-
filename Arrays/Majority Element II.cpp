class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/3];
    
    }
};