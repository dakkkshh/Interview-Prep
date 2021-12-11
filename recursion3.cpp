#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
void digitPrinter(int n){
    //base case
    if(n==0){
        return;
    }
    //current digit
    int current = n%10;
    digitPrinter(n/10);
    switch (current)
    {
    case 0:
        cout<<"zero"<<" ";
        break;
    case 1:
        cout<<"one"<<" ";
        break;
    case 2:
        cout<<"two"<<" ";
        break;
    case 3:
        cout<<"three"<<" ";
        break;
    case 4:
        cout<<"four"<<" ";
        break;
    case 5:
        cout<<"five"<<" ";
        break;
    case 6:
        cout<<"six"<<" ";
        break;
    case 7:
        cout<<"seven"<<" ";
        break;
    case 8:
        cout<<"eight"<<" ";
        break;
    case 9:
        cout<<"nine"<<" ";
        break;
    }
    //rec case
}
int strToInt(char *a,int n){
    if(n==0 ){
        return 0;
    }
    int digit = a[n-1] - '0'; //last digit
    int recNo = strToInt(a,n-1);
    return recNo*10 + digit;
}
void replacePI(char *a,int s){
    //base Case
    if(a[s]=='\0'){
        return;
    }
    if(a[s]=='p' and a[s+1]=='i'){
        //extend array at s+2th poistion by a factor of 2 and then replacement
        int j=s+2;
        while(a[j] !='\0'){
            j++;
        }
        //now j is at end means '\0'
        //Traverse towards back
        while(j>=(s+2)){
            a[j+2]=a[j];
            j--;
        }
        a[s]='3';
        a[s+1]='.';
        a[s+2]='1';
        a[s+3]='4';

        replacePI(a,s+4); //s+4 is the new starting index
    }else{
        replacePI(a,s+1);
    }
    return;
}
int tileProblem(int n){
    if(n>=1 and n<=3){
        return 1;
    }
    if(n<1){
        return 0;
    }
    if(n==4){
        return 2;
    }
    int totalWays = tileProblem(n-1)+tileProblem(n-4);
    return totalWays;
}
int ladderProblem(int n){
    if(n<0){
        return 0;
    }else if(n==0 or n==1){
        return 1;
    }else if(n==2){
        return 2;
    }else if(n==3){
        return 4;
    }
    return ladderProblem(n-1)+ladderProblem(n-2)+ladderProblem(n-3);
}
/*
int friendProblem(int n){
    if(n<=0){
        return 0;
    }else if(n==1){
        return 1;
    }
    return friendProblem(n-1)+friendProblem(n-2);
}*/
void moveDisc(int n,char source,char helper,char dest){
    //Base case
    if(n==0){
        return;
    }
    //rec case
    //move  n-1 disc from A to B
    moveDisc(n-1,source,dest,helper);
    //Left with Nth Disc in A
    cout<<"Shifted Disk:"<<n<<" From "<<source<<" to "<<dest<<endl;
    moveDisc(n-1,helper,source,dest);
}
int main(){
    //digitPrinter(2048);
    /*
    //STR TO INT
    char c[]="1234";
    int n = strlen(c);
    cout<<strToInt(c,n)<<endl;
    */
    /*
    //Replace "pi" with 3.14
    char c[1000] = "xpighpilmpipi";
    replacePI(c,0);
    int n = strlen(c);
    for(char x:c){
        cout<<x;
    }
    */
    /*

    //Tile Problem
    int n;cin>>n;cout<<tileProblem(n);
    */

    //Ladder Problem
    /*
    int n;cin>>n;cout<<ladderProblem(n);
    */

    //Friend Problem - LEARN PnC

    //Optimal Binary String - Learn
    //Hanoi Tower
    int n;cin>>n;moveDisc(n,'A','B','C');
    
    return 0;
}