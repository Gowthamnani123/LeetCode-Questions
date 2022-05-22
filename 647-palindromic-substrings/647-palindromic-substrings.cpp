class Solution {
public:
     int countSubstrings(string s) {
        int n = s.length();
        int res = n;
        for(int i=0;i<n;i++) {
            int j = i-1, k = i+1;
            while(j>=0 && k< n && (s[j--] == s[k++])) 
                res++;
            j = i, k = i+1;
            while(j>=0 && k< n && (s[j--] == s[k++]))
                res++;
        }
        
        return res;
    }
};