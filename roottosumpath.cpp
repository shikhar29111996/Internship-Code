/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void sum(TreeNode* root,vector<vector<int> >& so,int s,vector<int>& v)
{
    if(s==0 && root->left==NULL && root->right==NULL)
    {
        so.push_back(v);
    }
    
    if(root->left!=NULL)
    {
        v.push_back((root->left)->val);
        sum(root->left, so, s-(root->left)->val, v);
        v.pop_back();
    }
    
    if(root->right!=NULL)
    {
        v.push_back((root->right)->val);
        sum(root->right, so, s-(root->right)->val, v);
        v.pop_back();
    }
}

vector<vector<int> > Solution::pathSum(TreeNode* root,int s)
{
    vector<vector<int> > so;
    vector<int> v;
    
    if(root==NULL)
    {
        return so;
    }
    
    v.push_back(root->val);
    sum(root,so,s-root->val,v);
    
    return so;
}
