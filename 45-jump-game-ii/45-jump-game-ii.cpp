class Solution {
public:
    int jump(vector<int>& a)
    {
        int n=a.size();
        if(n==1)
            return 0;
        
        int j=0,curr_reach=0,max_reach=0;
        int i;
        
        for(i=0;i<n-1;i++)
        {
            max_reach=max(max_reach,i+a[i]);
            if(max_reach>=n-1)
                return j+1;
            
            if(i==curr_reach)
            {
                curr_reach=max_reach;
                j++;
            }
        }
        return j;
    }
};