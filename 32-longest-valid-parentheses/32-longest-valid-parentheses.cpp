class Solution {
public:
    int longestValidParentheses(string s)
    {
        int l=0,r=0,ans=0;
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
                l++;
            else
                r++;
            
            if(l==r)
                ans=max(ans,2*r);
            else if(r>l)
                l=r=0;
        }
        
        l=r=0;
        for(i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
                l++;
            else
                r++;
            
            if(l==r)
                ans=max(ans,2*l);
            else if(l>r)
                l=r=0;
        }
        return ans;
    }
};