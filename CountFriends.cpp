#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pf(n) cout << n << endl
#define ps() cout <<" ";
#define sf(n) cin >> n
#define in(i,n) for (int i = 0; i < n; i++)
#define vi vector<ll>
#define vp vector<pair<int, int>>
#define graph vector< vector<int> >
#define vs vector<string>

graph g(10010);
/**  '' "\n" ^ **/

int n,m,u,v;;
int a[100001];
int sz[100001];

void sieve()
{
    in(i,100001)
    {
        a[i]=i;
        sz[i]=1;
    }
}

int find(int x)
{
    if(x==a[x])return x;
    a[x]=find(a[x]);
    return a[x];
}

void unite(int A,int b)
{
    int r1=find(A);
    int r2=find(b);
    if(r1==r2)return;
    if(sz[r1]<sz[r2])
    {
        swap(r1,r2);
    }
    a[r2]=r1;
    sz[r1]+=sz[r2];
    return;
}
int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  sieve();
  sf(n);sf(m);
  in(i,m)
  {
      sf(u);sf(v);
      if(find(u)!=find(v))
      {
          unite(u,v);
          //cout<<u;ps();pf(find(u));
          //cout<<v;ps();pf(find(v));
      }
  }
  for(int i=1;i<=n;i++)
  {
      cout<<sz[find(i)]-1;ps();
  }
}
