class Solution {
public:
        bool backspaceCompare(string s, string t)
    {
        int i,j,ns=s.length(),nt=t.length();
        
        i=0,j=0;
        for(i=0;i<ns;i++)
        {
            if(s[i]=='#')
                j=max(0,j-1);
            else
                s[j++]=s[i];
        }
        ns=j;
        
        j=0;
        for(i=0;i<nt;i++)
        {
            if(t[i]=='#')
                j=max(0,j-1);
            else
                t[j++]=t[i];
        }
        nt=j;
        
        if(ns!=nt)
            return 0;
        
        for(i=0;i<ns;i++)
            if(s[i]!=t[i])
                return 0;
        
        return 1;
    }
};