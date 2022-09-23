class Solution {
public:
    int minDistance(string s1, string s2)
    {
        int n1=s1.length(),n2=s2.length();
        int i,j;
        int dp[n1+1][n2+1];
        
        for(i=0;i<=n1;i++)
        {
            for(j=0;j<=n2;j++)
            {
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
            }
        }
        
        return dp[n1][n2];
    }
};