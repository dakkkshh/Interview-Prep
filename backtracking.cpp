#include<iostream>
#include<set>
#include<string>
using namespace std;

bool ratInMaze(char maze[10][10],int sol[10][10],int i,int j,int m,int n){

    //Base Case
    if(i== m && j==n){
        sol[m][n]=1;
        //Print the path
        for(int k=0;k<=m;k++){
            for(int l=0;l<=n;l++){
                cout<<sol[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    //Rec Case
    //Rat should be in maze
    if(i>m || j>n){
        return false;
    }
    //Cell should not be blocked
    if(maze[i][j] =='X'){
        return false;
    }
    //Assume Solution exists through current Cell
    sol[i][j] = 1;
    //Checking answer from Right Side
    bool rightSide = ratInMaze(maze,sol,i,j+1,m,n);
    //Checking answer from Down Side
    bool downSide = ratInMaze(maze,sol,i+1,j,m,n);

    //Backtracking
    sol[i][j] = 0; 
    if(rightSide || downSide){
        return true;
    }
    return false;

}
void stringPermutation(char *in,int i,set<string> &s){
    //Base Case
    if(in[i]=='\0'){
        string t(in);
        s.insert(t);
        return;
    }
    //REC CASE

    for(int j=i;in[j]!='\0';j++){
        //Part of Down
        swap(in[i],in[j]);
        stringPermutation(in,i+1,s);
        //Part of UP
        //Backtracking- Restore original array
        swap(in[i],in[j]);
    }

}
int main(){
        /*
    //MAZE
    char maze[10][10]={"0000","00X0","000X","0X00"};
    int sol[10][10]={0};
    bool ans = ratInMaze(maze,sol,0,0,3,3);
    if(!ans){
        cout<<"Path Does not exsist"<<endl;
    }   */

    //STRING PERMUTATION
    char in[100];
    cin>>in;
    set<string> s;
    cout<<"-----------------------"<<endl;
    stringPermutation(in,0,s);
    for(auto x:s){
        cout<<x<<endl;
    }


    return 0;
}