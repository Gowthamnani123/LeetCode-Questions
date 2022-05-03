class Solution {
    vector<int>p; 
public:
    
    int findParent(int n){
        if(p[n]==n){
            return n; 
        }
        return p[n] = findParent(p[n]); 
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        p.resize(s.length());
        map<int , set<int>>obj;
        set<int>idx;
        string ans=s;
        
        
        for(int i=0; i<p.size(); i++){
            p[i]=i;
        }
        
        for(int i=0; i<pairs.size(); i++){
            int u = pairs[i][0];
            int v = pairs[i][1];
            int fx = findParent(u);
            int fy = findParent(v);
            
            if(fx!=fy){
                p[fy]=fx; 
            }
                 
        }
        for(int i=0; i<pairs.size(); i++){
            
            int u = pairs[i][0];
            int v = pairs[i][1];
            
            int fx = findParent(u);
            obj[fx].insert(u);
            obj[fx].insert(v);
              
        }
        
        for(auto it = obj.begin(); it!=obj.end(); it++){
            
            idx = it->second;
            vector<pair<char,int>>t; 
            auto index=idx.begin(); 
            
            for(index=idx.begin(); index!=idx.end(); index++){
                 
                 int pos = *index;
                 char ch = s[pos]; 
                 t.push_back({ch,pos}); 
            }
            
            sort(t.begin() , t.end()); 
            index=idx.begin(); 
            
            for(int i=0; i<t.size(); i++){ 
                 
                ans[*index] = t[i].first;
                index++; 
            } 
        
        }
       
        return ans;
    }
};