#include<bits/stdc++.h>
#define fin(x,y) for(int i=x;i<y;i++)
#define fp(v) for(auto val: v)
#define int long long
#define vec(v) vector<int> v
#define vp(v) vector<pair<int,int>> v
#define mi(m) map<int,int> m
#define msi(m) map<string,int> m 
#define v(all) v.begin(),v.end()
#define ac(v) accumulate(v.begin(),v.end(),0)
using namespace std;

void print(int i,vec(v),int a[],int n,int t){
    if(i==n){ 
        if(accumulate(v.begin(),v.end(),0)==t){
        fp(v){cout<<val<<" ";}cout<<endl;}
        return;
    }
    v.push_back(a[i]); //pick
    print(i+1,v,a,n,t);
    v.pop_back();      //not pick
    print(i+1,v,a,n,t);
}

signed main(){
    int a[]={3,1,2};
    int n=3,t=5;
    vec(v);
    print(0,v,a,n,t);
}