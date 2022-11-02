#include <bits/stdc++.h>
#define fr(x, y) for (int i = x; i < y; i++)
#define int long long
#define vec(v) vector<int> v
#define vp(v) vector<pair<int, int>> v
#define mi(m) map<int, int> m
#define msi(m) map<string, int> m

using namespace std;

void quicksort(int a[], int lo, int hi)
{   
    if(lo>=hi)return;
    int s = lo;
    int e = hi;
    int m = s + (e - s) / 2;
    int pivot = a[m];
    while(s<=e)
    {
        while (a[s] < pivot)
        {
            s++;
        }
        while (a[e] > pivot)
        {
            e--;
        }
        if(s<=e){
            int temp = a[s];
            a[s]=a[e];
            a[e]=temp;
            s++;
            e--;
        }

    }
    quicksort(a,lo,e);
    quicksort(a,s,hi);
    
}

signed main()
{
    int arr[5] = {3, 4, 2, 1, 5};
    quicksort(arr, 0, 4);
    fr(0,5)cout<<arr[i]<<" ";
}