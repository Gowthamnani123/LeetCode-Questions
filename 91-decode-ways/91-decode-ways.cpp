class Solution {
public:
   int numDecodings(string s)
    {
        if(s[0]=='0')
            return 0;
        
        int n=s.length();
        int dp[n];
        dp[0]=1;
        
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(s[i-1]=='1' || s[i-1]=='2')      
                    dp[i]=(i-2>=0)?dp[i-2]:1;
                else                                
                    return 0;
            }
            else
            {
                dp[i]=dp[i-1];                      
                
                if(s[i-1]!='0')
                {
                    string x="";
                    x+=s[i-1];
                    x+=s[i];
                    if(stoi(x)<=26)                 
                        dp[i]+=(i-2>=0)?dp[i-2]:1;
                }
            }
        }
        return dp[n-1];
    }
};