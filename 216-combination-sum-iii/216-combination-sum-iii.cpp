class Solution {
vector<vector<int>> ans;
public:
    int sum(vector<int>& c){
        int res= 0;
        for(auto x: c){
            res += x;
        }
        return res;
    }
    void combinationSumHelper(int k, int n, vector<int>& c, int num){
        
        if(k == 0){
            if(sum(c) == n ){
                ans.push_back(c);
            }
            return;
        }
        if(num > 9)
            return;
        
        c.push_back(num);
        combinationSumHelper(k - 1, n, c, num + 1);
        c.pop_back();
        combinationSumHelper(k, n, c, num + 1);    
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> c;
        combinationSumHelper(k, n, c, 1);
        return ans;
        
    }
};