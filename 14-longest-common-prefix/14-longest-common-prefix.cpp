class Solution {
public:
         string longestCommonPrefix(vector<string>& str)
    {
        sort(str.begin(),str.end());
        string s1=str[0];
        string s2=str.back();
        int n1=s1.length(),n2=s2.length();
        
        string ans="";
        
        for(int i=0;i<n1 && i<n2;i++)
        {
            if(s1[i]==s2[i])
                ans+=s1[i];
            else
                break;
        }
        return ans;
        
    }
};