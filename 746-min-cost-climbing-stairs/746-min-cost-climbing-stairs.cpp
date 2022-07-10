class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==2) return min(cost[0],cost[1]);
        int i;
        vector<int> dp(n+2);
        dp[0]=0;
        dp[0]=0;
        for(i=2;i<=n;i++){
            dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }
};