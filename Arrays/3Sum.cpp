class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector <int>> s;
    
        int target=0;

    for (int  i = 0; i < nums.size(); i++)
    {
        int j=i+1;
        int k=nums.size()-1;
        while (j<k)
        {
            int sum=nums[i] + nums[j] + nums[k];
            if (sum==target)
            {
                s.insert({nums[i] , nums[j] , nums[k] });
                j++;
                k--;
            }
            else if (sum<target)
            {
                j++;
            }
            else
            {
                k--;
            } 
            
        } 
        
    }
    vector <vector <int>> output;
        for (auto triplet:s)
            output.push_back(triplet);

    
    return output;
    }
};