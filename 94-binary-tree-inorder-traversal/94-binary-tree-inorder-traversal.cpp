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
    vector<int> inorderTraversal(TreeNode* root){
        if(!root)
            return {};
        TreeNode *curr=root;
        vector<int>ans;
        while(curr)
        {
            if(!curr -> left)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode *t=curr->left;
                
                while(t->right&&t->right!=curr)
                    t=t->right;
                
                if(!t->right)
                {
                    t->right=curr;
                    curr=curr->left;
                }
                else
                {
                    t->right=NULL;
                      ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
    
    return ans;
    }
};
        
        
 