#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
bool compare(string s1,string s2){
    if(s1.length()==s2.length()){
        return s1<s2; //comparing lexographically
    }
    return s2.length()>s1.length();
}
void sortString(string stringList[100],int n){
    for(int i=0;i<n;i++){
        getline(cin,stringList[i]);
    }
    sort(stringList,stringList+n,compare); //will sort according to lexographic
    for(int i=0;i<n;i++){
        cout<<stringList[i]<<endl;
    }
}
char *mystrtok(char *str,char delim){
    //String and a delim
    static char *input = NULL;
    //input will read number of tokens returned
    if(str!=NULL){
        //first call
        input = str;
    }
    //checking here for null input
    if(input == NULL){
        return NULL;
    }
    //Extracting tokens and will store them in an array
    char *output = new char[strlen(input)+1];//1 is for null char
    int i=0;
    for( ;input[i]!='\0';i++){
        if(input[i] != delim){
            output[i]=input[i];
        }else{
            output[i]='\0';
            input = input+i+1; //setting input to 
            return output;
        }
    }
    //corner case
    //for last word set a null at end in output and set input to null;
    output[i]='\0';
    input = NULL;
    return output;

}
int main(){
    /*string s,s1("Hello"),s2 = "Daksh";
    char a[] = {'a','b','c','\0'};
    string s3(a);
    cout<<s3<<endl;
    for(auto it=s2.begin();it!= s2.end();it++){ //auto = string::iterator
        cout<<(*it)<<".";
    }*/
    //String Sort
    /*
    int n;
    cin>>n;
    cin.ignore();
    string stringList[n];
    //sortString(stringList,n);
    */
   //String Tokenizer
   char s[100] = "Today, is, rainy, day";

   char *ptr = mystrtok(s,' ');
   cout<<ptr<<endl;
   while(ptr!= NULL){
       ptr = mystrtok(NULL,' ');
       cout<<ptr<<endl;
   }



    return 0;
}