class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int i,n=nums.size();
        int s=0;
        for(i=0;i<n;i++)
            s+=i-nums[i];
        s+=n;
        return s;
    }
};