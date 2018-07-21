/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 TreeLinkNode * getNextRight (TreeLinkNode * p)
 {
     TreeLinkNode * temp=p->next; //next node at same level
     while (temp) //further adjacent present in same level that  can provide us the children to point next to
     {
         if (temp->left) //simply it  will be pointer  as next
                return temp->left;
        if (temp->right) //else this will
                return temp->right;
        temp=temp->next; //else look for other adjacent at same level whose children can do the deed
     }
     
     return NULL;
 }
void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode * temp ;
    if (!A) return ;
    A->next=NULL;
    TreeLinkNode * p =A;
    
    //level by level
    while  (p!=NULL)
    {
        TreeLinkNode * q =p;
        //Connecting  children of p and  children of all nodes of same  level as p
        while (q!=NULL)
        {
            
            if (q->left)
            {
                if  (q->right) //it will be next of p s leftchild
                    q->left->next=q->right;
                else //some other children of some other  parent with same  level as p will be the next  for  p s left
                    q->left->next=getNextRight(q);
            }
            if (q->right) //for right child .. other parents of  same level as  p s children are the  only possible  next 
                q->right->next=getNextRight(q);
            
            //setting  all in this level
            q=q->next;
        }
        
        //this  level done 
        
        //preorder fashion for lower  nodes
        if (p->left)
                p=p->left; 
        else if (p->right)
                p=p->right;
        else p=getNextRight (p);
    }
    
}
