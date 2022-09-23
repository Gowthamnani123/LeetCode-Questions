class Solution {
public:
     int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int pos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                pos=i;
                break;
            }
        }
        if(nums[pos]!=1){
            return 1;
        }
        while(pos < nums.size()-1){
            if(nums[pos+1]-nums[pos]!=1 && (nums[pos+1]!=nums[pos])){
                return nums[pos]+1;
            }
            pos++;
        }
        int g = nums[nums.size()-1];
        return g+1;
    }
};