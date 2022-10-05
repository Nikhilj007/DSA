#include <bits/stdc++.h>
#include<vector>
using namespace std;

bool isprsnt(vector<int> v1,vector<int> v2){
   map<int,int> m;
   for(int i=0;i<v1.size();i++){
       m[v1[i]]++;
   }
   for(int i=0;i<v2.size();i++){
       m[v2[i]]++;
   }
   if(m.size()==5)return true;
   return false;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      for (int j = 0; j < a; j++)
      {
        int b;cin>>b;
	            v[i].push_back(b);
      }
    }
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (isprsnt(v[i], v[j]))
        {
          flag = 1;
          goto end;
        }
      }
    }
    end:
    if (flag)
      cout << "yes\n";
    else
      cout << "no\n";
  }
}