#include<iostream>
#include<cstring>
using namespace std;
void readLine(char ch[], int maxLength,char end = '\n'){
    int i=0;
    char c = cin.get();
    while(c != end){
        ch[i] = c;
        i++;
        if(1== maxLength -1 ){ //last bucket is reserved for null char
            break;
        }
        c = cin.get();
    }
    ch[i] = '\0';
}
bool isPalindrome(char a[]){
    int i=0,j = strlen(a) - 1; //Exempting Special Char

    while(i<j){
        if(a[i] == a[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}
void removeDuplicates(char a[]){
    int prev = 0,l=strlen(a); //j is prev and i is current
    if(l==1 || l==0){
        return;
    }
    for(int current = 1;current<l;current++){
        if(a[current]!=a[prev]){
            prev++;
            a[prev] = a[current];
        }
    }
    a[prev+1] = '\0'; //since prev will reach to only last char we add +1 to add null;
    return;
}
int main(){
    //Largest String
    char ch[1000],largest[1000];
    int n,currentLen = 0,largestLen = 0;
    cin>>n;
    cin.ignore();//It will read \n as a new character
    for(int i=0;i<n;i++){
        cin.getline(ch,1000); //works as readLine method
        currentLen = strlen(ch);
        if(currentLen>largestLen){
            largestLen = currentLen;
            strcpy(largest,ch);
        }

    }
    //readLine(ch,1000);
    /*if(isPalindrome(ch)){
        cout<<"Palindromic String:- "<<ch<<endl;
    }else{
        cout<<"It's Not A Palindromic String."<<endl;
    }*/
    //removeDuplicates(ch);
    cout<<"Largest Array is:- "<<largest<<" and Length is:- "<<largestLen<<endl;

    return 0;
}