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
         unordered_map<int,int> m;
    int i;
    
    TreeNode* buildTree(vector<int>& pre,vector<int>& in,int l,int r)
    {
        if(l>r)
            return NULL;
        
        TreeNode *root=new TreeNode(pre[i]);
        int mid=m[pre[i++]];
        
        root->left=buildTree(pre,in,l,mid-1);
        root->right=buildTree(pre,in,mid+1,r);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        int n=in.size();
        for(int i=0;i<n;i++)
            m[in[i]]=i;
        
        i=0;
        return buildTree(pre,in,0,n-1);
    }
};