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
     int inorder(TreeNode* root, int *k)
    {
        int ans=-1;
        
        if(root->left)
            ans=inorder(root->left,k);
        if(ans!=-1)
            return ans;
        
        (*k)--;
        if(*k==0)
            return root->val;
        
        if(root->right)
            ans=inorder(root->right,k);
        return ans;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        return inorder(root,&k);
       
    }
};