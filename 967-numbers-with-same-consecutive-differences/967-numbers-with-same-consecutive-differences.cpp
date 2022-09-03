class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> ans={1,2,3,4,5,6,7,8,9};
        
        while(--n)
        {
            vector<int> t;
            
            for(int num:ans)
            {
                int digit=num%10;
                
                if(digit+k<=9)
                    t.push_back(num*10+digit+k);
                
                if(k!=0 && digit-k>=0)
                    t.push_back(num*10+digit-k);
            }
            
            ans=t;
        }

        return ans;
    }
};