#include<bits/stdc++.h>
#define fr(x,y) for(int i=x;i<=y;i++)
#define int long long
#define vec(v) vector<int> v
#define vp(v) vector<pair<int,int>> v
#define mi(m) map<int,int> m
#define msi(m) map<string,int> m 

using namespace std;
// code to find all prime factors of a number by sieve of eratosthenes
void sieve(int n){
    int a[100]={0};

    fr(2,n){
       a[i]=i;
    }
    fr(2,n){
        if(a[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(a[j]==j)a[j]=i;
            }
        }
    }
    while(n!=1){
        cout<<a[n]<<endl;
       // cout<<n;
        n=n/a[n];
    }
}




signed main(){
   int n;
   cin>>n;
   sieve(n); 
}