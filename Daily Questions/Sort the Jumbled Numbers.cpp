class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<long long,vector<int> >mp;
        for(int i=0;i<nums.size();i++){
            vector<int>temp;
            int x=nums[i];
            if(x==0){
                mp[mapping[x]].push_back(x);
                continue;
            }
            while(x){
                temp.push_back(x%10);
                x/=10;
            }
            long long num=0;
            for(int j=temp.size()-1;j>=0;j--){
                num= (num*10) + mapping[temp[j]];
            }
            mp[num].push_back(nums[i]);
        }
        vector<int>ans;
        for(auto it:mp){
            for(auto x:it.second)
                ans.push_back(x);
        }
        return ans;
    }
};