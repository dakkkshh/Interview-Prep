#include<iostream>
#include<math.h>
#include<vector>
#include<bitset>
using namespace std;
//Native Approach
/*bool isPrime(int n){
    if(n==1){
        return false;
    }else if(n==2){
        return true;
    }
    
    for(int i=2;i<sqrt(n);i++){
        if(n%1==0){
            return false;
        }
    }
    return true;
}*/
//Sieve Based Approach
void primeSieve(){//Genearate array containing prime number
    int number;
    cin>>number;
    int p[1005] = {0}; //1=Prime;0=Non-Prime
    
    //Mark All Odd number prime
    for(int i=3;i<=1000;i+=2){
        p[i]=1;
    }
    //Sieve
    for(int i=3;i<=1000;i+=2){//jumping over odd numbers
        //if current number is not marked(it is prime)
        if(p[i]==1){
            //Mark Multiples as 0
            for(int j=2*i;j<=1000;j=j+i){
                p[j]=0;
            }
        }
    }
    //Special Case
    p[2]=1;
    p[1]=p[0]=0;

    for(int x=0;x<=number;x++){
        if(p[x]!=0){
            cout<<x<<" ";
        }
    }
}
void primeFactors(){
    //Prime Sieve
    int p[1005] = {0}; //1=Prime;0=Non-Prime
    
    //Mark All Odd number prime
    for(int i=3;i<=1000;i+=2){
        p[i]=1;
    }
    //Sieve
    for(int i=3;i<=1000;i+=2){//jumping over odd numbers
        //if current number is not marked(it is prime)
        if(p[i]){
            //Mark Multiples as 0
            for(int j=2*i;j<=1000;j=j+i){
                p[j]=0;
            }
        }
    }
    //Special Case
    p[2]=1;
    p[1]=p[0]=0;
    vector<int> primeNumber;
    //Inserting Numbers
    for(int x=0;x<=1000;x++){
        if(p[x]==1){
            primeNumber.push_back(x);
        }
    }
    //Factor
    int toFind;
    cin>>toFind;
    vector<int> factors;
    int pointer=0;
    int prime = primeNumber[0];
    while((prime*prime) <= toFind){  //from index to sqrt(toFind)
        if(toFind%prime==0){
            factors.push_back(prime);
            while((toFind%prime) == 0){
                toFind = toFind/prime;
            }
        }
        //go to the next position
        pointer++;
        prime = primeNumber[pointer];
    }
    if(toFind==1){
        factors.push_back(toFind);
    }
    for(auto value:factors){
        cout<<value<<" ";
    }
}
void primeFactorisation(){
    int primeCheck[1005]={0};
    for(int i=3;i<=1000;i+=2){
        primeCheck[i]=1;
    }
    for(int i=3;i<=1000;i+=2){
        if(primeCheck[i]){
            for(int j=2*i;j<=1000;j+=i){
                primeCheck[j]=0;
            }
        }
    }
    primeCheck[0]=primeCheck[1]=0;
    primeCheck[2]=1;
    vector<int> primeNumbers;
    for(int i=0;i<=1000;i++){
        if(primeCheck[i]){
            primeNumbers.push_back(i);
        }
    }
    int number,pointer=0,prime=primeNumbers[0],count;
    cin>>number;
    vector<pair<int,int>> factors;
    while((prime*prime)<=number){
        if(!(number%prime)){
            count=0;
            while((number%prime)==0){
                count++;
                number/=prime;
            }
            factors.push_back(make_pair(prime,count));
        }
        pointer++;
        prime = primeNumbers[pointer];
    }
    if(number!=1){//whatever is left is a prime number
        factors.push_back(make_pair(number,1));
    }
    for(auto x:factors){
        cout<<x.first<<"^"<<x.second<<endl;
    }
}
void divisorCount(){
    int p[1005] = {0}; //1=Prime;0=Non-Prime
    for(int i=3;i<=1000;i+=2){
        p[i]=1;
    }
    for(int i=3;i<=1000;i+=2){
        if(p[i]){
            for(int j=2*i;j<=1000;j=j+i){
                p[j]=0;
            }
        }
    }
    p[2]=1;
    p[1]=p[0]=0;
    vector<int> primeNumber;
    for(int x=0;x<=1000;x++){
        if(p[x]==1){
            primeNumber.push_back(x);
        }
    }
    int toFind;
    cin>>toFind;
    vector<int> factors;
    int pointer=0;
    int prime = primeNumber[0];
    int ans=1;
    while((prime*prime) <= toFind){  //from index to sqrt(toFind)
        if(toFind%prime==0){
            int count=0;
            while((toFind%prime) == 0){
                count++;
                toFind = toFind/prime;
            }
            ans*=(count+1);
        }
        //go to the next position
        pointer++;
        prime = primeNumber[pointer];
    }
    if(toFind!=1){
        ans*=2;
    }
    cout<<ans<<endl;
}

int main(){
    //primeSieve();
    //primeFactors();
    //primeFactorisation();
    //divisorCount();
    return 0;
}