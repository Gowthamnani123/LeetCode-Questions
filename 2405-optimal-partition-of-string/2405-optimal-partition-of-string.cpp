class Solution {
public:
    int partitionString(string s) {
        int n=s.size(),c=1;
        unordered_map<int, int> res;
     for(auto it:s)
        {
            if(res[it]!=0)
            {
                c++;
                res.clear();
            }
            res[it]++;
        }
        return c;
    }
};