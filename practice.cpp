#include<iostream>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include <bits/stdc++.h>
using namespace std;
//LINKED LIST USING CO PILOT
// class linkedList{
//     public:
//     int data;
//     linkedList *next;
//     linkedList(int data){
//         this->data=data;
//         this->next=NULL;
//     }
// };
// void print(linkedList *head){
//     linkedList *temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     cout<<endl;
// }
// //Add To Head
// void addToHead(linkedList *&head,int data){
//     linkedList *temp=new linkedList(data);
//     temp->next=head;
//     head=temp;
// }
// //Add To Tail
// void addToTail(linkedList *&head,int data){
//     linkedList *temp=new linkedList(data);
//     if(head==NULL){
//         head=temp;
//         return;
//     }
//     linkedList *temp1=head;
//     while(temp1->next!=NULL){
//         temp1=temp1->next;
//     }
//     temp1->next=temp;
// }
// //Add After
// void addAfter(linkedList *&head,int data,int key){
//     linkedList *temp=new linkedList(data);
//     linkedList *temp1=head;
//     while(temp1!=NULL){
//         if(temp1->data==key){
//             temp->next=temp1->next;
//             temp1->next=temp;
//             return;
//         }
//         temp1=temp1->next;
//     }
// }
// //Add Before
// void addBefore(linkedList *&head,int data,int key){
//     linkedList *temp=new linkedList(data);
//     linkedList *temp1=head;
//     if(temp1->data==key){
//         temp->next=temp1;
//         head=temp;
//         return;
//     }
//     while(temp1->next!=NULL){
//         if(temp1->next->data==key){
//             temp->next=temp1->next;
//             temp1->next=temp;
//             return;
//         }
//         temp1=temp1->next;
//     }
// }
// //Delete From Head
// void deleteFromHead(linkedList *&head){
//     if(head==NULL){
//         return;
//     }
//     linkedList *temp=head;
//     head=head->next;
//     delete temp;
// }
// //Delete From Tail
// void deleteFromTail(linkedList *&head){
//     if(head==NULL){
//         return;
//     }
//     linkedList *temp=head;
//     if(temp->next==NULL){
//         head=NULL;
//         delete temp;
//         return;
//     }
//     while(temp->next->next!=NULL){
//         temp=temp->next;
//     }
//     linkedList *temp1=temp->next;
//     temp->next=NULL;
//     delete temp1;
// }
// //Delete After
// void deleteAfter(linkedList *&head,int key){
//     if(head==NULL){
//         return;
//     }
//     linkedList *temp=head;
//     while(temp->next!=NULL){
//         if(temp->data==key){
//             linkedList *temp1=temp->next;
//             temp->next=temp->next->next;
//             delete temp1;
//             return;
//         }
//         temp=temp->next;
//     }
// }
// //Delete Before
// void deleteBefore(linkedList *&head,int key){
//     if(head==NULL){
//         return;
//     }
//     linkedList *temp=head;
//     if(temp->data==key){
//         head=head->next;
//         delete temp;
//         return;
//     }
//     while(temp->next!=NULL){
//         if(temp->next->data==key){
//             linkedList *temp1=temp->next;
//             temp->next=temp->next->next;
//             delete temp1;
//             return;
//         }
//         temp=temp->next;
//     }
// }
// //Delete All
// void deleteAll(linkedList *&head){
//     if(head==NULL){
//         return;
//     }
//     linkedList *temp=head;
//     while(temp!=NULL){
//         linkedList *temp1=temp;
//         temp=temp->next;
//         delete temp1;
//     }
//     head=NULL;
// }
// //Circular Linked List
// void circularLinkedList(linkedList *&head){
//     if(head==NULL){
//         return;
//     }
//     linkedList *temp=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=head;
// }
// //Reverse Circular Linked List
// void reverseCircularLinkedList(linkedList *&head){
//     if(head==NULL){
//         return;
//     }
//     linkedList *temp=head;
//     linkedList *temp1=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=head;
//     while(temp1->next!=head){
//         temp1=temp1->next;
//     }
//     temp1->next=NULL;
//     head=temp;
// }
// //Reverse Linked List
// void reverseLinkedList(linkedList *&head){
//     if(head==NULL){
//         return;
//     }
//     linkedList *temp=head;
//     linkedList *temp1=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=head;
//     while(temp1->next!=head){
//         temp1=temp1->next;
//     }
//     temp1->next=NULL;
//     head=temp;
// }
// //Reverse Linked List Recursive
// void reverseLinkedListRecursive(linkedList *&head){
//     if(head==NULL){
//         return;
//     }
//     linkedList *temp=head;
//     linkedList *temp1=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=head;
//     while(temp1->next!=head){
//         temp1=temp1->next;
//     }
//     temp1->next=NULL;
//     head=temp;
//     reverseLinkedListRecursive(head);
// }
// //Loop Detection
// bool loopDetection(linkedList *head){
//     if(head==NULL){
//         return false;
//     }
//     linkedList *temp=head;
//     linkedList *temp1=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=head;
//     while(temp1->next!=head){
//         temp1=temp1->next;
//     }
//     temp1->next=NULL;
//     return true;
// }
// //Remove Loop
// void removeLoop(linkedList *head){
//     if(head==NULL){
//         return;
//     }
//     linkedList *temp=head;
//     linkedList *temp1=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=head;
//     while(temp1->next!=head){
//         temp1=temp1->next;
//     }
//     temp1->next=NULL;
// }
// //Remove Loop Recursive
// void removeLoopRecursive(linkedList *head){
//     if(head==NULL){
//         return;
//     }
//     linkedList *temp=head;
//     linkedList *temp1=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=head;
//     while(temp1->next!=head){
//         temp1=temp1->next;
//     }
//     temp1->next=NULL;
//     removeLoopRecursive(head);
// }
// //Remove Loop Iterative
// void removeLoopIterative(linkedList *head){
//     if(head==NULL){
//         return;
//     }
//     linkedList *temp=head;
//     linkedList *temp1=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=head;
//     while(temp1->next!=head){
//         temp1=temp1->next;
//     }
//     temp1->next=NULL;
// }



// Remove Duplicates from array
int removeDuplicates(int arr[], int n) {
    if(n==0){
        return 0;
    }
    int i=0;
    int j=1;
    while(j<n){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
        j++;
    }
    return i+1;
}
// //Remove Duplicates from Linked List
// void removeDuplicatesLL(linkedList *&head){
//     if(head==NULL){
//         return;
//     }
//     linkedList *temp=head;
//     linkedList *temp1=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=head;
//     while(temp1->next!=head){
//         temp1=temp1->next;
//     }
//     temp1->next=NULL;
// }
//DNF Sort
void dnfSort(int arr[], int n){
    if(n==0){
        return;
    }
    int i=0;
    int j=n-1;
    while(i<j){
        while(arr[i]<0){
            i++;
        }
        while(arr[j]>0){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
}
//Wave sort
void waveSort(int arr[], int n){
    if(n==0){
        return;
    }
    int i=0;
    int j=n-1;
    while(i<j){
        while(arr[i]<0){
            i++;
        }
        while(arr[j]>0){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
}
//Merge two Sorted Array without using extra space
void mergeTwoSortedArray(int arr1[], int n1, int arr2[], int n2){
    if(n1==0){
        return;
    }
    int i=0;
    int j=0;
    int k=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr1[k]=arr1[i];
            i++;
        }
        else{
            arr1[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr1[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr1[k]=arr2[j];
        j++;
        k++;
    }
}

//Median of two sorted array
int medianOfTwoSortedArray(int arr1[], int n1, int arr2[], int n2){
    if(n1==0){
        return arr2[n2/2];
    }
    if(n2==0){
        return arr1[n1/2];
    }
    int i=0;
    int j=0;
    int k=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
        k++;
    }
    while(i<n1){
        i++;
        k++;
    }
    while(j<n2){
        j++;
        k++;
    }
    if(k%2==0){
        return (arr1[k/2]+arr2[k/2])/2;
    }
    else{
        return arr1[k/2];
    }
}

int main(){
    int n;
    cin>>n;
    bool flag;
    flag=false;
    for(int i=0;i<n/2;i++){
        if(n%i==0){
            flag=true;    
            break;
        }
    }
    if(flag){
        cout<<"Not a Prime Number"<<endl;
    }else{
        cout<<"Prime Number"<<endl;
    }
    return 0;
}
