class Solution {
public:
    string longestPalindrome(string s) {
     int n=s.length();
        int i;
        int mx=1,b=0,e=0;
        for(i=0;i<n-1;i++)
        {
            int l=i;
            int r=i+1;
            int len=0;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
                len+=2;
            }
            if(len>mx)
            {
                mx=len;
                b=l+1;
                e=r-1;
            }
            
            l=i-1;
            r=i+1;
            len=1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
                len+=2;
            }
            if(len>mx)
            {
                mx=len;
                b=l+1;
                e=r-1;
            }            
        }
        string ans="";
        for(i=b;i<=e;i++)
            ans+=s[i];
        return ans;
    }
};