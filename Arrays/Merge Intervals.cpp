class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<=1){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merged;
        for(int i=0;i<n;i++){
            int cs=intervals[i][0];
            int ce=intervals[i][1];
            //merge overlapped intervals
            while(i+1<n && intervals[i+1][0]<=ce){
                ce=max(ce,intervals[i+1][1]);
                i++;
            }
            merged.push_back({cs,ce});
        }
        return merged;
    }
};