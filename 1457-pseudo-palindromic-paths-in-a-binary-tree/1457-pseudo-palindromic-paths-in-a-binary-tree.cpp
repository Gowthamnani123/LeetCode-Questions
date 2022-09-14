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
   unordered_set<int> s;
    int ans;
    
    void find(TreeNode* root)
    {   
        if(!root)
            return;
        
        if(s.find(root->val)==s.end())
            s.insert(root->val);
        else
            s.erase(root->val);
        
        if(!root->left && !root->right)
        {
            if(s.size()<=1)
                ans++;
        }
        else
        {
            find(root->left);
            find(root->right);
        }
        
        if(s.find(root->val)==s.end())
            s.insert(root->val);
        else
            s.erase(root->val);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ans=0;
        find(root);
        return ans;
    }
};