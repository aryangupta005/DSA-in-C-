class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>numMap;
        int n=nums.size();
        //Build Hashtable 
        for(int i=0;i<n;i++){
            numMap[nums[i]]=i;
        }
        //Find Compliment 
        for(int i=0;i<n;i++){
            int compliment=target-nums[i];
            if(numMap.count(compliment)&&numMap[compliment]!=i){
                return{i,numMap[compliment]};
            }
        }
        return{};
    }
};