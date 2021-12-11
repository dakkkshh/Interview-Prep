#include<iostream>
using namespace std;
int main(){
    //Array Allocation
    //Static Controlled by compiler
    int a[100];
    cout<<sizeof(a)<<endl;
    //Dynamic
    int n;
    cin>>n;
    int *b = new int[n]{0}; //sets b array to 0;
    /*for(int i=0;i<n;i++){
        cout<<b[i]<<endl;
    }*/
    //free up space
    delete [] b;
    //2-D Dynamic Array
    /*
    int **arr = NULL;//points to pointer of 1-D array
    int r,c;
    cin>>r>>c;
    //Array of Rows Heads
    arr = new int*[r];//pointer of 1-D array
    //2-D array
    for(int i=0;i<r;i++){
        arr[i] = new int[c];//Each 1-D head will have c elements
    }
    //cin and cout
    int val = 1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr[i][j] = val;
            cout<<arr[i][j];
            val++;
        }
        cout<<endl;
    }*/
    
    return 0;
}