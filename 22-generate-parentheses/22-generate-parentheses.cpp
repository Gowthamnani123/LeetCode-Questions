class Solution {
public:
     void helper(int open, int close, int n, string curr, vector<string>& op){
        if (open == n && close == n){
            op.push_back(curr);
            return;
        }
        if (open<n){
            helper(open+1, close, n, curr+"(", op);
        }
        if (close<open){
            helper(open, close+1, n, curr+")", op);
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> op;
        helper(0, 0, n, "", op);
        return op;
    }
};
