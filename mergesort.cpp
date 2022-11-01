#include<bits/stdc++.h>
#define fr(x,y) for(int i=x;i<y;i++)
#define int long long
#define vec(v) vector<int> v
#define vp(v) vector<pair<int,int>> v
#define mi(m) map<int,int> m
#define msi(m) map<string,int> m 

using namespace std;

void merge(int arr[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1],b[n2];

    fr(0,n1){
        a[i]=arr[l+i];
    }
    fr(0,n2){b[i]=arr[mid+i+1];}

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++; k++;
        }
        if(a[i]>b[j]){
            arr[k]=b[j];
            k++; j++;
        }    
    }

    while(i<n1){
        arr[k]=a[i];
        k++; i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++; j++;
    }
}


void mergesort(int arr[],int l,int r){
    if(l<r){
    int mid=(l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);

    merge(arr,l,mid,r);
    }
}

signed main(){
   int arr[]={3,2,5,4,1};
   mergesort(arr,0,4); 
   fr(0,5){
    cout<<arr[i]<<" ";
   }
}