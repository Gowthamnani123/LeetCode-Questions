class Solution {
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string t,ans="";
        
        while(ss>>t)
        {
            reverse(t.begin(),t.end());
            ans+=t;
            ans+=' ';
        }
        
        ans.pop_back();
        return ans;
    }
};