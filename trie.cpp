#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    bool isTerminal;
    char data;
    unordered_map<char, node*> children;

    node(char d){
        data = d;
        isTerminal = false;
    }
};
class Trie{
    node *root;
    int count;
    public:
    Trie(){
        root = new node('\0');
        count=0;
    }
    void insert(char *w){
        node *temp = root;
        //Temp will start from root
        for(int i=0;w[i]!='\0';i++){
            char ch = w[i];
            if(temp->children.count(ch)){
                //Move temp to next Node
                temp = temp->children[ch];
            }else{
                //Create new node
                node *n = new node(ch);
                temp->children[ch] = n;
                temp=n;
            }
        }
        //We are at last Node
        temp->isTerminal = true;
        return;
    }
    bool find(char *w){
        node *temp = root;
        for(int i=0;w[i]!='\0';i++){
            char ch = w[i];
            if(temp->children.count(ch)==0){
                return false;
            }else{
                temp = temp->children[ch];
            }
        }
        return temp->isTerminal;
    }
    void uniquePrefixArray(char input[10][10]){
        bool check=false;
        for(int i=0;i<5;i++){
            char *w = input[i];
            node *temp = root;
            for(int j=0;w[j]!='\0';j++){
                char ch = w[j];
                if(temp->children.count(ch)>1){
                    cout<<w[j];
                    temp = temp->children[ch];
                }else if(temp->children.count(ch)==1){
                    cout<<w[j];
                    check=true;
                    break;
                }   
            }
            if(!check){
                //Not found
                cout<<"-1";
                check=false;
            }
            cout<<endl;
        }
        return;    
    }
};
//Left is 0 Right is 1
class node2{
    public:
    node2 *left;
    node2 *right;
};
class Trie2{
    node2 *root;
    public:
    Trie2(){
        root = new node2();
    }
    //Assuming n is 32 bit integer
    void insert(int n){
        node2 *temp = root;
        for(int i=31;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit==0){
                if(temp->left==NULL){
                    temp->left = new node2();
                }
                temp = temp->left;
            }else{
                if(temp->right==NULL){
                    temp->right = new node2();
                }
                temp = temp->right;
            }
        }
        return;
    }
    //Helper to find max XOR
    int maxXORHelper(int value){
        node2 *temp = root;
        int currentAns = 0;
        for(int j=31;j>=0;j--){
            int bit = (value>>j)&1;
            if(bit==0){
                //Find bit 0;
                if(temp->right!=NULL){
                    currentAns += (1<<j);
                    temp = temp->right;
                }else{
                    temp = temp->left;
                    //Taking 0 will not contribute to ans
                }
            }else{
                if(temp->left!=NULL){
                    currentAns += (1<<j);
                    temp = temp->left;
                }else{
                    temp = temp->right;
                }
            }
        }
        return currentAns;
    }
    int maxXOR(int *input,int n){
        int maxAns = 0;
        for(int i=0;i<n;i++){
            int val = input[i];
            insert(val);
            int currentAns = maxXORHelper(val);
            cout<<currentAns<<" ";
            maxAns = max(maxAns,currentAns);
        }
        return maxAns;
    }
};

int main()
{
    // Trie t;
    // char words[][10]={"cobra","cobras","dog","dove","duck"};
    // for(int i=0;i<5;i++){
    //     t.insert(words[i]);
    // }
    // t.uniquePrefixArray(words);

    //MAX XOR PAIR
    // int input[]={3,10,5,25,2,8};
    // Trie2 t;
    // cout<<t.maxXOR(input,6);


    return 0;
}