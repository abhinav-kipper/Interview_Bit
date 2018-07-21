/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool ispresent(TreeNode * root,int  x)
 {
     if (!root) return 0;
     if (root->val==x) return 1;
     
     return ispresent(root->left,x) || ispresent(root->right,x);
 }
 int lca_bt(TreeNode * root,int  a,int b)
 {
     if (!root) return -1;
     
     if (root->val==a || root->val==b) 
            return root->val;
    
     int  left=lca_bt(root->left,a,b);
     int  right=lca_bt(root->right,a,b);
     
     if (left!=-1 && right!=-1)
            return root->val;
    
    if (left!=-1) return left;
    return right;
            
 }
int Solution::lca(TreeNode* A, int B, int C) {
    if (!ispresent(A,B) || !ispresent(A,C) || !A) return -1;
    
    return lca_bt(A,B,C);
}
