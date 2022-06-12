class Solution {
public:
   string convert(string s, int m) {
        int n = s.length();
        if(n<=m) return s;
        
        string t[m], ans;
        int i = 0;
        while(1){
            for(int j = 0;i<n && j< m; j++,i++){
                t[j] += s[i];
            }
            if(i==n) break;
            for(int j = m-2; j>0 && i<n; j--,i++){
                t[j] += s[i];
            }
            if(i==n) break;
        }
        
        for(int i = 0; i<m; i++){
            ans += t[i];
        }
        
        return ans;
    }
};