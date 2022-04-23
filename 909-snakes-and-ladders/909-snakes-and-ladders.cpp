class Solution {
public:
        int find(int x,vector<vector<int>>& a,int n)
    {
        int cr,cc;
        x--;
        cr=n-x/n-1;
        cc=x%n;
        
        bool rev=0;
        if(n%2==0)
            rev=(cr%2==0);
        else
            rev=(cr%2!=0);
        
        if(rev)
            cc=n-cc-1;
        
        if(a[cr][cc]!=-1)
            return a[cr][cc];
        else
            return x+1;
    }
    
    int snakesAndLadders(vector<vector<int>>& a)
    {
        int n=a.size();
        if(n==1)
            return 0;
        
        unordered_set<int> vis;
        queue<int> q;
        q.push(1);
        vis.insert(1);
        
        int ans=0;
        
        
        while(!q.empty())
        {
            int s=q.size();
            ans++;
            
            while(s--)
            {
                int beg=q.front();
                q.pop();
                
                for(int i=1;i<7 && beg+i<=n*n;i++)
                {
                    int end=find(beg+i,a,n);
                    if(end==n*n)
                        return ans;
                    
                    if(vis.find(end)==vis.end())
                    {
                        q.push(end);
                        vis.insert(end);
                    }
                }
            }
        }
        
        return -1;
    }
};