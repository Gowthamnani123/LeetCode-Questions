/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     map<int,multiset<pair<int,int>>> m;
    
    void traverse(TreeNode* root,int col,int level)
    {
        if(!root)
            return;
        
        m[col].insert({level,root->val});
        
        traverse(root->left,col-1,level+1);
        traverse(root->right,col+1,level+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> ans;             
        traverse(root,0,0);
        
        for(auto it:m)
        {
            vector<int> t;
            
            for(auto p:it.second)
            t.push_back(p.second);
            
            ans.push_back(t);
        }
            
        
        return ans;
    }
};