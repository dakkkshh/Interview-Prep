// Intro
// search operation in binary tree is expensive O(N)
// BST is special binary tree in which elements are ordered such that root.left 
// containes elemnet<root.data (for all nodes in left)and 
// root.right contains element with value>root.data(for all nodes in right)
// each subtree is a BST. Search is O(D) where D is depth of tree
// in best case D= LogN in worst case it is N(Skewed Tree-LinkedList)
#include<iostream>
#include<queue>
#include<climits>
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
//Accepts old root node and data and return new root node
node *insertInBST(node *root,int d){
    //Base case
    if(root==NULL){
        return new node(d);
    }
    //Rec Case
    if(d<=root->data){
        root->left=insertInBST(root->left,d);
    }else{
        root->right=insertInBST(root->right,d);
    }
    return root;
}
node *build(){
    //Read list of numbers till -1
    int d;
    cin>>d;
    node *root=NULL;
    while(d!=-1){
        root=insertInBST(root,d);
        cin>>d;
    }
    return root;
}
//print bst level by level
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
bool search(node *root,int d){
    if(root==NULL){
        return false;
    }
    if(d==root->data){
        return true;
    }
    if(d<root->data){
        return search(root->left,d);
    }else{
        return search(root->right,d);
    }
    return false;
}
node *deleteNode(node *root,int data){
    if(root==NULL){
        return NULL;
    }else if(data<root->data){
        root->left=deleteNode(root->left,data);
        return root;
    }else if(data==root->data){
        //Found data then 3 case possible
        //0 Child
        if(root->left==NULL and root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        if(root->left!=NULL and root->right==NULL){
            //there's subtree in left side of root
            node *temp=root->left;
            delete root;
            return temp;
        }if(root->right!=NULL and root->left==NULL){
            node *temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        //Find in order successor in right Side i.e. minimum in right Sub tree
        if(root->left!=NULL and root->right!=NULL){
            node *replace = root->right;
            while(replace->left!=NULL){
                replace=replace->left;    
            }
            root->data=replace->data;
            root->right = deleteNode(root->right,replace->data);
            return root;
        }
    }else{
        root->right=deleteNode(root->right,data);
        return root;
    }
    return root;

}
bool isBST(node *root,int minValue=INT_MIN,int maxValue=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data >= minValue and root->data <=maxValue and isBST(root->left,minValue,root->data) and isBST(root->right,root->data,maxValue)){
        return true;
    }
    return false;
}
class LinkedList{
    public:
        node *head;
        node *tail;
};
LinkedList flatten(node *root){
    LinkedList l;
    if(root==NULL){
        //Empty Tree
        l.head=l.tail=NULL;
        return l;
    }

    //Leaf Node
    if(root->left==NULL and root->right==NULL){
        //Head awa Tail
        l.head=l.tail=root;
        return l;
    }
    //Left is not null
    if(root->left!=NULL and root->right==NULL){
        LinkedList leftHS=flatten(root->left);
        leftHS.tail->right=root;

        l.head=leftHS.head;
        l.tail=root;
        return l;
    }
    //Right is not NULL
    if(root->left==NULL and root->right!=NULL){
        LinkedList rightHS=flatten(root->right);
        root->right=rightHS.head;

        l.head=root;
        l.tail=rightHS.tail;
        return l;
    }
    //Both side are not null
    //Post order left-right-root
    LinkedList LeftLL= flatten(root->left);
    LinkedList RightLL = flatten(root->right);

    LeftLL.tail->right=root;
    root->right = RightLL.head;

    l.head=LeftLL.head;
    l.tail=RightLL.tail;

    return l;


}
int main(){

    node *root=build();
    bfsLevel(root);
    cout<<endl;
    //Inorder of BST is always sorted

    //Search
    // int n;cin>>n;
    // cout<<endl;
    // if(search(root,n)){
    //     cout<<"true";
    // }else{
    //     cout<<"false";
    // }

    //Delete
    // int n;cin>>n;
    // deleteNode(root,n);
    // bfsLevel(root);
    // cout<<endl;

    //Check BST
    // cout<<endl;
    // if(isBST(root)){
    //     cout<<"True";
    // }else{
    //     cout<<"False";
    // }

    //Flattening a Tree

    
    return 0;
}