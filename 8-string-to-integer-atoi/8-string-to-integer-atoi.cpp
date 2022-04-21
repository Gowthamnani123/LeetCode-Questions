class Solution {
public:
         int myAtoi(string s)
    {
        int n=s.length();
        int i=0;
        long ans=0;
        int sign=1;
        
        while(s[i]==' ')
            i++;
        
        if(s[i]=='+')
            i++;
        else if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        
        for(i;i<n;i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                ans=(ans*10)+(s[i]-'0');
            }
            else
                break;
            
            if(ans>INT_MAX)
            {
                if(sign==1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }                
        }
        
        if(sign==1)
            return ans;
        else
            return -ans;   
    }
};