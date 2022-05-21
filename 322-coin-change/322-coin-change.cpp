class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n=coins.size();
        int i,j;
        
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        
        for(i=0;i<n;i++)
        {
            for(j=1;j<=amount;j++)
            {
                if(coins[i]<=j && dp[j-coins[i]]!=INT_MAX)
                {
                    dp[j]=min(dp[j],dp[j-coins[i]]+1);
                }
            }
        }
        
        if(dp[amount]==INT_MAX)
            return -1;
        
        return dp[amount];
    }
};