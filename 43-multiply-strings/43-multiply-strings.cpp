class Solution {
public:
     string multiply(string n1, string n2) 
    {
        if(n1=="0" || n2=="0")
            return "0";
        
        int l1=n1.length(),l2=n2.length();
        vector<int> res(l1+l2,0);
        string ans="";
        int i,j;
        
        for(i=l2-1;i>=0;i--)
        {
            for(j=l1-1;j>=0;j--)
            {
                res[i+j+1]+=((n2[i]-'0')*(n1[j]-'0'));
                res[i+j]+=res[i+j+1]/10;
                res[i+j+1]%=10;
            }
        }
        
        for(i=0;i<l1+l2;i++)
        {
            if(res[i]!=0)
                break;
        }
        
        for(i;i<l1+l2;i++)
            ans+=to_string(res[i]);
        
        return ans;
    }
};