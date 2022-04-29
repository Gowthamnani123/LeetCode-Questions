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
     void inorder(stack<int> &ans,TreeNode* r)
    {
        if(!r)
            return;
        
        inorder(ans,r->right);
        ans.push(r->val);
        inorder(ans,r->left);        
    }
    
    vector<int> getAllElements(TreeNode* r1, TreeNode* r2) {
        vector<int> ans;
        stack<int> t1,t2;
        inorder(t1,r1);
        inorder(t2,r2);
        
        while(!t1.empty() && !t2.empty())
        {
            if(t1.top()<=t2.top())
            {
                ans.push_back(t1.top());
                t1.pop();
            }
            else
            {
                ans.push_back(t2.top());
                t2.pop();
            }
        }
        while(!t1.empty())
        {
            ans.push_back(t1.top());
            t1.pop();
        }
        
        while(!t2.empty())
        {
            ans.push_back(t2.top());
            t2.pop();
        }
        
        return ans;
    }
};