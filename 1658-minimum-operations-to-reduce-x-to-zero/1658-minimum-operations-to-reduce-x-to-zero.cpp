class Solution {
public:
    int subarrayLength(vector<int>&v,int target){
        int sum=0;int j=0;int ans=-1;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            
            while(sum>target){
                sum-=v[j];
                j++;
            }
            if(sum==target){
                ans=max(ans,i-j+1);
            }
        }
        return ans;
    }
    int minOperations(vector<int>& nums, int x) {
        
        int sum= accumulate(nums.begin(),nums.end(),0);
        int target= sum-x;
        if(target<0) return -1;
        int length= subarrayLength(nums,target);
        if(length==-1){
            return -1;
        }
        return nums.size()-length;
    }
};