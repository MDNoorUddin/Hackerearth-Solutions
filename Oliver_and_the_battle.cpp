

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
    /**  '' "\n" ^ */
     
    string str;
    int p[10010];
    vector<int> ans;
    int a[1010][1010];
    int n,m;
    int total,mx=0;
     
    int c=0;
     
    void dfs(int i,int j)
    {
        c++;
        a[i][j]=0;
        if(i+1<n)
        {
            if(a[i+1][j]==1)
                dfs(i+1,j);
            if(j-1>=0&&a[i+1][j-1]==1)
            {
                dfs(i+1,j-1);
            }
            if(j+1<m&&a[i+1][j+1]==1)
            {
                dfs(i+1,j+1);
            }
        }
        if(j+1<m&&a[i][j+1]==1)
        {
            dfs(i,j+1);
        }
        if(j-1>=0&&a[i][j-1]==1)
        {
            dfs(i,j-1);
        }
     
        if(i-1>=0)
        {
            if(a[i-1][j]==1)
                dfs(i-1,j);
            if(j-1>=0&&a[i-1][j-1]==1)
            {
                dfs(i-1,j-1);
            }
            if(j+1<m&&a[i-1][j+1]==1)
            {
                dfs(i-1,j+1);
            }
        }
    }
    int main() {
     
      ios::sync_with_stdio(false);
      cin.tie(0);
      int t;
      sf(t);
      while(t--)
      {
          sf(n);sf(m);
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<m;j++)
                sf(a[i][j]);
          }
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<m;j++)
              {
                  if(a[i][j]==1)
                  {
                      dfs(i,j);
                      total++;
                      mx=max(mx,c);
                      c=0;
                  }
              }
          }
          cout<<total;ps();pf(mx);
          total=0;mx=0;
      }
    }
