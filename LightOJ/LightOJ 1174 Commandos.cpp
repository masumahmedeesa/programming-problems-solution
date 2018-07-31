#include<bits/stdc++.h>
#define MAX 107
using namespace std;

vector<int>adj[MAX];
bool visited[MAX];
int countd,y,n;
int time1[MAX];
int time2[MAX];

void edge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool check()
{
    for(int i=0; i<n; i++)
        if(visited[i]==false)
            return false;
    cout<<"bal"<<endl;
    return true;
}
void dfs(int u)
{
    //countd++;

    //if(u==y)
    //return;
    if(visited[u]==false)
    {
        //visited[u]=true;
        bool x=check();
        if(x==true)
        {
            if(u==y)
                cout<<"vxd"<<endl;
            return;
        }


        //else
        //return;
        //countd++;
        visited[u]=true;
        for(int i=0; i<(int)adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(!visited[v])
                dfs(v);
        }
        countd++;
    }
    //else
    //countd-=1;
}

void bfs(int u,int time[])
{
    queue<int>q;
    visited[u]=true;
    time[u]=0;
    q.push(u);
    while(!q.empty())
    {
        int vr=q.front();
        q.pop();
        for(int i=0; i<adj[vr].size(); i++)
        {
            int v=adj[vr][i];
            if(visited[v]==false)
            {
                visited[v]=true;
                time[v]=time[vr]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int cases;
    cin>>cases;
    int caseno=1;
    while(cases--)
    {

        countd=0;
        int e;
        cin>>n>>e;
        for(int i=0; i<n; i++)
            adj[i].clear();
        //for(int i=0;i<n;i++)
        //visited[i]=false;
        memset(visited,false,sizeof(visited));
        int flag=1;
        for(int i=0; i<e; i++)
        {
            int u,v;
            cin>>u>>v;
            edge(u,v);
        }
        int x;
        cin>>x>>y;
        //countd=0;
        //dfs(x);
        //if(e%2!=0)
        //cout<<"Case "<<caseno++<<": "<<countd<<endl;
        //else
        //clr(time1);
        memset(time1,0,sizeof(time1));
        memset(time2,0,sizeof(time2));
        bfs(x,time1);
        memset(visited,false,sizeof(visited));
        bfs(y,time2);
        int mx=0;
        for(int i=0;i<n;i++)
            mx=max(mx,time1[i]+time2[i]);

        cout<<"Case "<<caseno++<<": "<<mx<<endl;
        //cout<<countd<<endl;
    }
}

/*

3
3 2
0 1
0 2
0 2
3 2
0 1
0 2
2 0
3 2
1 2
1 0
1 0

*/

