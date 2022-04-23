class Solution {
public:
        void nextPermutation(vector<int>& nums)
    {
        int i,j;
        int n=nums.size();
        int in=-1;
        for(i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                in=i-1;
                break;
            }
        }
        
        if(in==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        j=in+1;
        for(i=in+2;i<n;i++)
        {
            if(nums[i]>nums[in] && nums[i]<=nums[j])
                j=i;
        }
        
        swap(nums[in],nums[j]);
        reverse(nums.begin()+in+1,nums.end());
    }
    
};