class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        
        int s,e,i;
        s=intervals[0][0];
        e=intervals[0][1];
        
        for(i=1;i<n;i++)
        {
            if(intervals[i][0]<=e)
                e=max(e,intervals[i][1]);
            else
            {
                ans.push_back({s,e});
                s=intervals[i][0];
                e=intervals[i][1];
            }                
        }
        ans.push_back({s,e});
        return ans;
        
    }
};