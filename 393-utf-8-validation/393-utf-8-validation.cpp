class Solution {
public:
    bool validUtf8(vector<int>& data)
    {
        int i,n=data.size();
        
        i=0;
        while(i<n)
        {
            int x=data[i++];
            int l;
            
            if(x>>7==0b0)
                continue;
            
            if(x>>3==0b11110)
                l=4;
            else if(x>>4==0b1110)
                l=3;
            else if(x>>5==0b110)
                l=2;
            else
                return 0;
            
            
            l=l-1;
            while(l && i<n)
            {
                if(data[i++]>>6!=0b10)
                    return 0;
                
                l--;
            }

            if(l>0)
                return 0;
            
        }
        
        return 1;
    }
};
    