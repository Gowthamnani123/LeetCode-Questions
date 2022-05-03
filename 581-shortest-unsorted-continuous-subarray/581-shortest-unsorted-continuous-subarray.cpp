class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
         int n=nums.size(),i,j;
        int s=-1,e=n;
        int mn=INT_MAX,mx=INT_MIN;
        
        for(i=n-1,j=0;i>=0;i--,j++)
        {
            if(nums[i]<=mn)
                mn=nums[i];
            else
                s=i;
            
            if(nums[j]>=mx)
                mx=nums[j];
            else
                e=j;
        }
        
        if(s==-1)
            return 0;
        
        return e-s+1;
        
    }
};