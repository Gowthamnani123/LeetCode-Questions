class Solution {
public:
    string countAndSay(int n)
    {   
        string s="1";
        
        while(--n)
        {
            string ans="";
            int c=0;
            char ch=s[0];
            
            for(char x:s)
            {
                if(x==ch)
                    c++;
                else
                {
                    ans+=(c+'0');
                    ans+=ch;
                
                    ch=x;
                    c=1;
                }
            }
            ans+=(c+'0');
            ans+=ch;
            s=ans;
        }
        return s;
    }
};