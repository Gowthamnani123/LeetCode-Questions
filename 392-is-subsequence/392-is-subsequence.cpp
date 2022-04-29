class Solution {
public:
     bool isSubsequence(string s, string t) {
        int m,n;
        m=t.length();
        n=s.length();
        if(n>m)
            return 0;
        if(n==0)
            return 1;
        
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        if(i==n)
            return 1;
        return 0;
    }
};