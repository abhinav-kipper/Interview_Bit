 int swap  (int  &a,int &b) { int temp=a; a=b;b=temp;}

void permutations(vector<vector<int> > &res,vector<int > &a,int left,int right)
{

    if  (left==right)
    {
       res.push_back(a);
        //count++;
        return ;
    }
    for (int i=left;i<=right;i++)
    {
        swap (a[i],a[left]);
        permutations(res,a,left+1,right);
        swap (a[i],a[left]);
    }
    
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int  >> res;
    vector<int > a;
    permutations(res,A,0,A.size()-1);
    return res;
}
