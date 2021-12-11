#include<bits/stdc++.h>
#include<queue>
using namespace std;
class node{
        
    public:
        int data;
        node *left,*right;
        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};
node* buildTree(){
    int d;
    cin>>d;
    
    //Base case
    if(d==-1){
        return NULL;
    }
    node *root = new node(d);
    //Rec case
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void print(node *root){//Preorder
    //root then left then right
    //Base case
    if(root==NULL){
        return;
    }
    //Print root then left and then right
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);

    return;
}
void inorderPrint(node *root){
    //left then root then right
    if(root==NULL){
        return;
    }
    //Left then root then right
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
    return;
}
int height(node *root){
    if(root==NULL){
        return 0;
    }
    int ls=height(root->left);
    int rs=height(root->right);
    //+1 for the root node/ current node
    return max(ls,rs)+1;
}
void printKlevel(node *root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){//k equivalent to ck hence if ck==1 right Node
        cout<<root->data<<" ";
        return;
    }
    printKlevel(root->left,k-1);
    printKlevel(root->right,k-1);
    return;
}
void printAllLevel(node *root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        printKlevel(root,i);
        cout<<endl;
    }
    return;
}
int count(node *root){
    if(root==NULL){
        return 0;
    }
    //1 for the self node
    return 1+count(root->left)+count(root->right);
}
void bfsLevel(node *root){
    queue<node*> q;
    q.push(root);
    //Since first node is root
    q.push(NULL);
    while(!q.empty()){
        node *cur = q.front();
        //New Line Print Logic
        //if first elem is NULL new line is created
        if(cur==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                //Pushing NULL for second Line
                q.push(NULL);
            }
        }else{
            cout<<cur->data<<" ";
            q.pop();
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
        }    
    }
    return;
}
int diameter(node *root){
    if(root==NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);

    int op1=h1+h2;
    //Pre order
    int op2=diameter(root->left);
    int op3=diameter(root->right);

    return max(op1,max(op2,op3));

}
class Pair{
    public:
        int h;//height
        int d;//diameter

};
Pair fastDiameter(node *root){
    //Difficult Logic
    Pair p;
    if(root==NULL){
        p.d=0;
        p.h=0;
        return p;
    }
    //Here is POST ORDER TRAVERSAL
    //left right then root
    Pair leftSide=fastDiameter(root->left);
    Pair rightSide=fastDiameter(root->right);
    //+1 for the self node diameter
    p.h=max(leftSide.h,rightSide.h)+1;
    p.d=max(leftSide.h+rightSide.h,max(leftSide.d,rightSide.d));
    return p;
}
int replaceSum(node *root){
    if(root==NULL){
        return 0;
    }
    //if leaf node
    if(root->left==NULL and root->right==NULL){
        return root->data;
    }
    //Rec part
    int leftSum=replaceSum(root->left);
    int rightSum=replaceSum(root->right);
    int temp=root->data;
    root->data=leftSum+rightSum;

    return temp+root->data;
}
class HBpair{
    public:
        int height;
        bool balanced;
};
HBpair isHeightBalanced(node *root){
    HBpair p;
    if(root==NULL){
        p.height=0;
        p.balanced=true;
        return p;
    }
    //Rec Call
    HBpair leftSide=isHeightBalanced(root->left);
    HBpair rightSide=isHeightBalanced(root->right);
    p.height=max(leftSide.height,rightSide.height)+1;
    if(abs(leftSide.height-rightSide.height)<=1 and leftSide.balanced and rightSide.balanced){
        p.balanced=true;
    }else{
        p.balanced=false;
    }
    return p;
}
node *buildBalancedTree(int *a,int s,int e){
    //Base case
    if(s>e){
        return NULL;
    }
    //rec case
    int mid=(s+e)/2;
    node *root= new node(a[mid]);
    root->left=buildBalancedTree(a,s,mid-1);
    root->right=buildBalancedTree(a,mid+1,e);
    return root;
}
node* inPreTree(int *in,int *pre,int s,int e){
    static int i=0;//pointer to point to pre
    //Base case
    if(s>e){
        return NULL;
    }
    //Rec Case
    node *root = new node(pre[i]);
    int index=-1;//Index of pre[i] in "in"
    for(int j=s;j<=e;j++){
        if(in[j]==pre[i]){
            index=j;
            break;
        }
    }
    i++;
    root->left=inPreTree(in,pre,s,index-1);
    root->right=inPreTree(in,pre,index+1,e);
    return root;
}
void printRightView(node *root,int level,int &maxLevel){
    if(root==NULL){
        return;
    }
    
    if(maxLevel<level){
        //New level discovery hence print root->data
        cout<<root->data<<" ";
        maxLevel=level;
    }
    //Traverse in right then left
    printRightView(root->right,level+1,maxLevel);
    printRightView(root->left,level+1,maxLevel);
    return;
}
//Print nodes at distance K from Target Node
//case 1 Kth level print
void printSubtreeNodes(node *root,int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
    return;
}

//case 2
int printNodesAtK(node *root,node *target,int k){
    //this function print nodes and returns distance too
    if(root==NULL){
        return -1;//Can not find target Node 
    }
    if(root==target){
        printSubtreeNodes(root,k);
        return 0;
    }
    //DL= distance from ancestor in left
    //DR= distance from ancestor in right
    int dl=printNodesAtK(root->left,target,k);
    if(dl!=-1){
        //We found target in left Subtree
        if(dl+1==k){
            //current node is at kth distance from target node
            cout<<root->data<<" ";
        }else{
            printSubtreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr=printNodesAtK(root->right,target,k);
    if(dr!=-1){
        //We found target in left Subtree
        if(dr+1==k){
            //current node is at kth distance from target node
            cout<<root->data<<" ";
        }else{
            printSubtreeNodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}
//assumption both a and b are present, all keys are unique
node *lca(node *root,int a ,int b){
    //Base case
    if(root==NULL){
        return NULL;
    }
    if(root->data==a || root->data==b){
        //data has been found in given subtree
        return root;
    }
    //Search in Left and Right
    node *leftAns=lca(root->left,a,b);
    node *rightAns=lca(root->right,a,b);

    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }
    if(leftAns!=NULL){
        return leftAns;
    }
    return rightAns;
}
int findMaxUtil(node* root, int &res)
{
    //Base Case
    if (root == NULL)
        return 0;
 
    // l and r store maximum path sum going through left and
    // right child of root respectively
    int l = findMaxUtil(root->left,res);
    int r = findMaxUtil(root->right,res);
 
    // Max path for parent call of root. This path must
    // include at-most one child of root
    int max_single = max(max(l, r) + root->data, root->data);
 
    // Max Top represents the sum when the Node under
    // consideration is the root of the maxsum path and no
    // ancestors of root are there in max sum path
    int max_top = max(max_single, l + r + root->data);
 
    res = max(res, max_top); // Store the Maximum Result.
 
    return max_single;
}
 
// Returns maximum path sum in tree with given root
int findMaxSum(node *root)
{
    // Initialize result
    int res = INT_MIN;
 
    // Compute and return result
    findMaxUtil(root, res);
    return res;
}
int findLevel(node *root,int key,int level){
    //finding level from root node or a particular node
    if(root==NULL){
        return -1;
    }
    if(root->data==key){
        return level;
    }
    int leftAns=findLevel(root->left,key,level+1);
    if(leftAns!=-1){
        return leftAns;
    }
    return findLevel(root->right,key,level+1);
}

int findMinDist(node *root,int a,int b){
    node *lcaNode=lca(root,a,b);
    //level of a from lca Node
    int l1= findLevel(root,a,0);
    int l2=findLevel(root,b,0);
    return l1+l2;
}
int main(){
    //node *root=buildTree();
    // print(root);
    // cout<<endl;
    // cout<<"--"<<endl;
    // cout<<height(root)<<endl;
    // inorderPrint(root);
    // printAllLevel(root);
    //bfsLevel(root);
    //cout<<diameter(root)<<endl;
    // Pair p=fastDiameter(root);
    // cout<<p.h<<endl;
    // cout<<p.d<<endl;
    // bfsLevel(root);
    // cout<<"--"<<replaceSum(root);
    // cout<<endl;
    // bfsLevel(root);
    // cout<<endl;
    // cout<<"Height:- "<<isHeightBalanced(root).height<<endl;
    // cout<<"Bool:- "<<isHeightBalanced(root).balanced<<endl;

    //Balanced Tree from Array
    // int n;cin>>n;int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // node *root=buildBalancedTree(arr,0,n-1);
    // bfsLevel(root);

    //In+pre unique tree
    // int in[]={3,2,8,4,1,6,7,5};
    // int pre[]={1,2,3,4,8,5,6,7};
    // node *root=inPreTree(in,pre,0,7);
    // bfsLevel(root);

    // node *root=buildTree();
    // int maxLevel=-1;
    // printRightView(root,0,maxLevel);

    

    return 0;
}