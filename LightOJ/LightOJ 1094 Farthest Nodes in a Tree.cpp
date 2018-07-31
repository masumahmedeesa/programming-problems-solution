#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<assert.h>
#include<string.h>

#define MX 30007
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<int,int>
#define FOR(i,n) for(int i=0;i<(int)n;i++)
using namespace std;

vector<pii>cost[MX];
//vector<int>adj[MX];
long long sum;
int dist[MX];
bool visited[MX];

void bfs(int u)
{
    queue<int>q;
    q.push(u);
    dist[u]=0;
    visited[u]=true;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int i=0;i<(int)cost[v].size();i++){
            int vr=cost[v][i].first;
            if(visited[vr]==false){
                visited[vr]=true;
                dist[vr]=dist[v]+cost[v][i].second;
                //cout<<dist[vr]<<endl;
                q.push(vr);
            }
        }
    }
}
int main()
{
    int cases,caseno=1;
    cin>>cases;
    while(cases--)
    {
        sum=0;
        mem(dist,0);
        mem(visited,false);

        int node;
        cin>>node;
        FOR(i,node)
            cost[i].clear();

        FOR(i,node-1)
        {
            int u,v,w;
            cin>>u>>v>>w;
            //adj[u].push_back(v);
            //adj[v].push_back(u);
            cost[u].push_back(pii(v,w));
            cost[v].push_back(pii(u,w));
        }
        bfs(0);
        int src=0;
        FOR(i,node)
        {
            if(dist[src]<dist[i])
                src=i;
            visited[i]=false;
        }
        bfs(src);
        cout<<"Case "<<caseno++<<": "<<*max_element(dist,dist+node)<<endl;
    }
}

