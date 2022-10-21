#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
       char a[8][8];
       int r,b;
       for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>a[i][j];
        }
       }
       for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(a[i][j]=='R')r++;
            else if(a[i][j]=='B')b++; 
        }
        if(r==8){cout<<"R\n"; goto end;}
        if(b==8){cout<<"B\n"; goto end;}
        r=0;
        b=0;
       }
       for(int j=0;j<8;j++){
        for(int i=0;i<8;i++){
            if(a[i][j]=='R')r++;
            else if(a[i][j]=='B')b++; 
        }
        if(r==8){cout<<"R\n"; goto end;}
        if(b==8){cout<<"B\n"; goto end;}
        r=0;
        b=0;
       }
       end:;
    }
    return 0;
}
