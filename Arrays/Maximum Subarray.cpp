class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            ans=max(ans,sum);   
        }
        if (ans == 0) {
            ans = INT_MIN;
            for (int i = 0; i < n; ++i) {
                ans = max(ans, nums[i]);
            }
        }
        return ans;
    return 0;    
    } 
};