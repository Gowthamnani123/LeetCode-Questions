class Solution {
public:
     vector<int> getRow(int r)
    {
        vector<int> v={1};
        int i;
        long c=1;
        
        for(i=0;i<r;i++)
        {
            c=c*(r-i)/(i+1);
            v.push_back(c);
        }
        
        return v;
    }
};