#include<iostream>
using namespace std;
int hourGlassSum(int a[3][3]){
    int sum=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            sum += a[i][j];
        }
    }
    return sum;
}
int main(){
    int arr[6][6];
    int currentArr[3][3];
    int maxHourGlass = INT_MIN;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int currentRow = i;
            int currentCol = j;
            for(int k=0;k<3;k++){
                currentCol = j;
                for(int l=0;l<3;l++){
                    currentArr[k][l] = arr[currentRow][currentCol];
                    currentCol++;
                }
                currentRow++;
            }
            currentArr[1][0] = 0;
            currentArr[1][2] = 0;
            int currentSum = hourGlassSum(currentArr);
            maxHourGlass = max(currentSum,maxHourGlass);
        }
    }
    cout<<maxHourGlass<<endl;
    
    return 0;
}
