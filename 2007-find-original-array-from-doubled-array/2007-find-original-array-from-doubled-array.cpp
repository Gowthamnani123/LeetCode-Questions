class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        int i,j,n=a.size();
        vector<int> ans;
        
        if(n%2!=0)
            return {};
        
        map<int,int> m;
        
        for(i=0;i<n;i++)
            m[a[i]]++;
        
        for(auto it:m)
        {
            while(m[it.first]>0)
            {
                m[it.first]--;
                if(m[2*it.first]<=0)
                    return {};
            
                m[2*it.first]--;
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};