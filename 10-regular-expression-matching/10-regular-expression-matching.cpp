class Solution {
public:
    int dp[21][31];
bool func(int i,int j,string &s,string &p){
    if(dp[i][j] != -1) return dp[i][j];
    if(i >= s.size()){
        if(j == p.size()) return dp[i][j] = true;
        if(j + 1 < p.size() && p[j + 1] == '*') return dp[i][j] = func(i,j + 2,s,p);
        return dp[i][j] = false;
    }
    else if(j == p.size()) return dp[i][j] = false;
    bool match = (s[i] == p[j] || p[j] == '.');
    bool ans = false;
    if(match){
        if(j + 1 < p.size() && p[j + 1] == '*') ans = func(i+1,j,s,p);
        if(!ans) ans = func(i + 1,j + 1,s,p);
    }
    if(!ans && j + 1 < p.size() && p[j + 1] == '*') ans = func(i,j + 2,s,p);
    return dp[i][j] = ans;
}
bool isMatch(string s, string p) {
    memset(dp,-1,sizeof dp);
    return func(0,0,s,p);
}
};