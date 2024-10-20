class Solution {
void solve(vector<int>& nums,vector<int> output,int index,vector<vector<int>>& ans){
    // base case 
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }
    // exclude
    solve(nums,output,index+1,ans);
    // include
    int element=nums[index];
    output.push_back(element);
    solve(nums,output,index+1,ans);
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        
        // Sort the nums array to handle duplicates
        sort(nums.begin(), nums.end());
        
        solve(nums, output, index, ans);
        
        // Sort the resulting subsets and remove duplicates
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
    
};
