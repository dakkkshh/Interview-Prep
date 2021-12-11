#include<iostream>
using namespace std;
void firstOcc(int s,int e,int arr[],int key){
    if(s==e){
        cout<<"Not Found";
        return;
    }
    static int pos=0;
    if(key==arr[s]){
        cout<<pos<<endl;
        return;
    }
    pos++;
    firstOcc(s+1,e,arr,key);   
}
void bubbleSort(int *arr,int n){
    //base case
    if(n==1){
        return;
    }
    //rec Case this will perform Pass
    for(int j=0;j<n-1;j++){ //n-1 as last one will be sorted itself
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
    bubbleSort(arr,n-1);
}
void bubbleSortRec(int *arr,int j,int n){
    //ending/base case
    if(n==1){
        return;
    }
    //if pass is complete then take a next pass to check 
    if(j==n-1){
        return bubbleSortRec(arr,0,n-1);
    }
    //if pass is not completed and executing then check for swapping
    if(arr[j]>arr[j+1]){
        swap(arr[j],arr[j+1]);
    }
    bubbleSortRec(arr,j+1,n);
    return;
}
void mergeArray(int *arr,int s,int e){
    int mid = (s+e)/2;
    //Merge 2 Array
    int i=s,k=s,j=mid+1;
    int temp[e];
    while(i<=mid and j<=e){
        if(arr[i]<arr[j]){
            temp[k]=arr[i]; //same as separate increment
            k++;
            i++;
        }else{
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid){//j has reaches its end
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j<=e){//i has reaches its end
        temp[k]= arr[j];
        k++;
        j++;
    }
    //copy to original array
    for(int i=s;i<=e;i++){
        arr[i]=temp[i];
    }
}
void mergeSortRec(int *arr,int s,int e){
    //Base Case for 1/0 elemets
    if(s>=e){
        return;
    }
    //Mid Point
    int mid = (s+e)/2;
    //Rec Array(s,mid) and (mid+1,e);
    mergeSortRec(arr,s,mid);
    mergeSortRec(arr,mid+1,e);
    //Merge Array
    mergeArray(arr,s,e);   
}
int partitionQS(int *a,int s,int e){
    //Inplace hence can not take extra array
    int i=s-1;
    int pivot = a[e];
    for(int j=s;j<e;j++){
        if(a[j]<=pivot){// e is pivot and current element is smaller than pivot
            //Merge smaller element in region 1-"Small REGION"
            i++;
            swap(a[i],a[j]);
        }
        //Expand large region which is done by for loop's j++;
    }
    //place pivot element in correct index
    swap(a[i+1],a[e]);
    return i+1;
}
void quickSort(int *a,int s,int e){ 
    //base case
    if(s>=e){
        return;
    }
    int p = partitionQS(a,s,e);
    //Rec Case
    quickSort(a,s,p-1);//left part
    quickSort(a,p+1,e);//right part
}
int mergeIC(int *a,int s,int e){
    int mid = (s+e)/2;
    int i=s; //array A's Pointer
    int j=mid+1;//array B's Pointer
    int k=s;//will be used to check 

    int temp[1000];
    int count=0;//check cross inversions;
    while(i<=mid and j<=e){
        if(a[i]<=a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
            //IMPORTANT STEP BELOW
            count+=(mid-i+1);
        }
    }
    //fill array if some elements are left due to "and" operation
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++] = a[j++];
    }
    for(int i=s;i<=e;i++){
        a[i]=temp[i];
    }
    return count;

}
int inversionCount(int *a,int s,int e){
    //base case
    if(s>=e){
        return 0;
    }
    //merge Sort
    int mid = (s+e)/2;
    int x = inversionCount(a,s,mid);
    int y = inversionCount(a,mid+1,e);
    int z = mergeIC(a,s,e);

    return x+y+z;
}
void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    /*
    int arr[]={1,2,3,7,4,5,6,7};
    int key=7;
    int n = sizeof(arr)/sizeof(int);
    firstOcc(0,n,arr,key);
    */
    //BUBBLE SORT
    /*
    int arr[]={5,4,3,1,2};
    bubbleSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
    cout<<"--------------"<<endl;
    bubbleSortRec(arr,0,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<",";
    }
    */
    /*
    //MERGE SORT
    int arr[]={5,6,1,2,4,0};
    mergeSortRec(arr,0,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<",";
    }*/
    /*
    //QUICK SORT
    int a[] = {2,7,8,6,1,5,4};
    int n = sizeof(a)/sizeof(int);
    quickSort(a,0,n-1);
    printArray(a,n);
    */
    //INVERSION COUNT
    int a[]={1,5,2,6,3,0};
    int n = sizeof(a)/sizeof(int);
    cout<<inversionCount(a,0,n-1)<<endl;
    printArray(a,n);
    return 0;
}