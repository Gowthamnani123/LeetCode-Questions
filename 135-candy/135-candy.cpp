class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i;
        vector<int> l(n,1);
        int ans=0;
        
        for(i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
                l[i]=l[i-1]+1;
        }
        
        ans+=l[n-1];
        for(i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                l[i]=max(l[i],l[i+1]+1);
            
            ans+=l[i];
        }
        
        return ans;
    }
};