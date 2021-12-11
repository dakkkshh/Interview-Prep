#include<iostream>
#include<algorithm>
using namespace std;
void wavePrint(int arr[100][100],int m,int n){
    for(int i=0;i<n;i++){
        //col then row and check condition
        if(i%2==0){
            //even-top to bottom
            for(int j=0;j<m;j++){
                cout<<arr[j][i]<<" ,";
            }
        }else{
            //odd-bottom to top
            for(int j=m-1;j>=0;j--){
                cout<<arr[j][i]<<" ,";
            }
        }
    }

}
void spiralPrint(int a[][100],int m,int n){
    int startRow = 0,endRow = m-1,startCol = 0,endCol = n-1;
    while(startRow <= endRow and startCol <= endCol){
        //First Row or Top Row
        for(int i=startCol;i<=endCol;i++){
            cout<<a[startRow][i]<<" ,";
        }
        startRow++;
        //Last Col
        for(int i=startRow;i<=endRow;i++){
            cout<<a[i][endCol]<<" ,";
        }
        endCol--;
        //Last Row or Bottom Row
        if(endRow>=startRow){
            for(int i=endCol;i>=startCol;i--){
            cout<<a[endRow][i]<<" ,";
        }
        endRow--;
        }
        //Start Col
        if(endCol>=startCol){
            for(int i=endRow;i>=startRow;i--){
            cout<<a[i][startCol]<<" ,";
        }
        startCol++;
        }
    }
}
void rotateArray(int arr[100][100],int n){
    //Reverse Each Row
    for(int row = 0;row<n;row++){
        int startCol=0;
        int endCol = n-1;
        while(startCol<endCol){
            swap(arr[row][startCol],arr[row][endCol]);
            startCol++;
            endCol--;
        }
    }
    //Transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                swap(arr[i][j],arr[j][i]);
            }
        }
    }
}
void rotateSTL(int arr[100][100],int n){
    //Reverse array using STL reverse(start_container,end_container)
    for(int i=0;i<n;i++){
        reverse(arr[i],arr[i]+n);
    }
    //Transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                swap(arr[i][j],arr[j][i]);
            }
        }
    }
}
bool staricaseSearch(int arr[100][100],int m,int n,int key){
    int i = 0,j=n-1;
    while( i<m and j>=0){
        if(arr[i][j]==key){
            return true;
        }else if(arr[i][j]>key){
            j--;
        }else{
            i++;
        }
    }
    return false;
}
int main(){
    int arr[100][100];
    int m,n; //row and col
    int key;
    cin>>m>>n>>key;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    //WavePrint
    //wavePrint(arr,m,n);
    //spiralPrint(arr,m,n);
    //rotateArray(arr,m);
    //rotateSTL(arr,m);
    cout<<"----------------------------------"<<endl;
    /*for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/
    if(staricaseSearch(arr,m,n,key)){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    return 0;
}