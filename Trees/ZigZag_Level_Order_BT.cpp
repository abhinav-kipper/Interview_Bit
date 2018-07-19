/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    stack<TreeNode*> cur,next;
    bool left=true;
    cur.push(A);
    vector<vector<int >> res;
        vector<int > r;
    while (!cur.empty())
    {
        TreeNode *  element=cur.top();
        cur.pop();
    
        r.push_back(element->val);
        if (left)
        {
            if (element->left)
            next.push(element->left);
            if (element->right)
            next.push(element->right);
        }
        else
        {
            if (element->right)
            next.push(element->right);
            if (element->left)
            next.push(element->left);
        }
                
            if (cur.empty())
            {
                swap ( cur,next);
                left=!left;
                res.push_back(r);    
                r.clear();
            }
            
    }
    return res;
}

