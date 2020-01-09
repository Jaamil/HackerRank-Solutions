
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 100000

vector<int>graph[mx+10];
int visit[mx+10];
int n, test, m, r, l, x, y, cnt;

void ini()
{
    cnt = 0;
    for(int i=0;i<=n;i++)
    {
        graph[i].clear();
        visit[i] = 0;
    }
}

void dfs(int s)
{
    for(int i=0;i<graph[s].size();i++)
    {
        int nxt = graph[s][i];
        if(visit[nxt]==0)
        {
            visit[nxt] = 1;
            cnt++;
            dfs(nxt);
        }
    }
}

int main()
{

    cin>>test;
    while(test--){
        cin>>n>>m>>l>>r;

        ll ans = 0;
        ini();

        while(m--)
        {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for(int i=1;i<=n;i++)
        {
            if(visit[i]==0)
            {
                cnt = 0;
                dfs(i);
                if(cnt==0) cnt = 1;
                ans+= min((ll)(cnt-1)*(ll)r+(ll)l, (ll)cnt*(ll)l);
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
