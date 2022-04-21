class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)  {
        int n1=nums1.size(),n2=nums2.size();
        if((n1+n2)==1)
        {
            if(n1)
                return nums1[0];
            return nums2[0];
        }
        int i,j,mid;
        double ans=0;
        bool o=(n1+n2)%2;
        i=0,j=0;
        mid=(n1+n2)/2;
        while(i<n1 && j<n2 && mid!=1)
        {
            if(nums1[i]<=nums2[j])
                i++;
            else
                j++;
            
            mid--;
        }
        if(mid!=1)
        {
            while(i<n1 && mid!=1)
            {
                i++;
                mid--;
            }
            
            while(j<n2 && mid!=1)
            {
                j++;
                mid--;
            }
        }
        if(i<n1 && j<n2)
        {
            if(nums1[i]<=nums2[j])
            {
                if(!o)
                ans=nums1[i];
                i++;
            }
            else
            {
                if(!o)
                ans=nums2[j];
                j++;
            }
        }
        else if(i!=n1)
        {
            if(!o)
            ans=nums1[i];
            i++;
        }
        else
        {
            if(!o)
            ans=nums2[j];
            j++;
        }
        
        if(i<n1 && j<n2)
            ans+=min(nums1[i],nums2[j]);
        else if(i!=n1)
            ans+=nums1[i];
        else
            ans+=nums2[j];
        
        if(o)
            return ans;
        return ans/2;
    }
};