class Solution {
public:
    int dp[200][200];
    int tmp[200][200];
    int ans = 0;
    int findMaxForm(vector<string>& strs, int m, int n) {
        for (auto pei: strs)
        {
            int cnt1 = 0;
            int cnt0 = 0;
            for (auto nei: pei)
            {
                if (nei == '1')
                    cnt1++;
                else
                    cnt0++;
            }
            for (int i = cnt1; i <= n; i++)
            {
                for (int j = cnt0; j <= m; j++)
                {
                    tmp[i][j] = max(dp[i][j], dp[i - cnt1][j - cnt0] + 1);
                }
            }
            for (int i = cnt1; i <= n; i++)
            {
                for (int j = cnt0; j <= m; j++)
                {
                    dp[i][j] = tmp[i][j];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
        
    }
};