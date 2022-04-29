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
    bool isSymmetric(TreeNode* root) {
            
        if(!root)
            return 1;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty())
        {
            TreeNode *l,*r;
            
            l=q.front();
            q.pop();
            
            r=q.front();
            q.pop();
            
            if(!l && !r)
                continue;
            
            if(!l || !r || l->val!=r->val)
                return 0;
            
            q.push(l->left);
            q.push(r->right);
            
            q.push(l->right);
            q.push(r->left);
        }
        return 1;
    }
};