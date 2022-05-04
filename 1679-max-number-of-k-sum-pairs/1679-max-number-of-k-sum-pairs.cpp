class Solution {
public:
   int maxOperations(vector<int>& a, int k)
    {
        sort(a.begin(),a.end());
        int i,j,c=0;
        i=0,j=a.size()-1;
        while(i<j)
        {
            int s=a[i]+a[j];
            if(s==k)
            {
                c++;
                i++;
                j--;
            }
            else if(s<k)
                i++;
            else
                j--;
        }
        return c;
    }
};