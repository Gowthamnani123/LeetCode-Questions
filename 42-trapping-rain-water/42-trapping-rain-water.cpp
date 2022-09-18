class Solution {
public:
    int trap(vector<int>& a)
    {
        int n=a.size();
        int l=0,r=n-1,maxl=0,maxr=0;
        int ans=0;
        
        while(l<=r)
        {
            maxl=max(a[l],maxl);
            maxr=max(a[r],maxr);
            
            if(maxl<=maxr)
            {
                ans+=maxl-a[l];
                l++;
            }
            else
            {
                ans+=maxr-a[r];
                r--;
            }
        }
        
        return ans;
    }
};