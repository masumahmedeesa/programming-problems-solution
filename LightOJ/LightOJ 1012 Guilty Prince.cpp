#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<(int)n;i++)
#define MX 35
#define pi pair<int,int>
#define mem(x,y) memset(x,y,sizeof(x))

using namespace std;

int x,y,countd;
char cost[MX][MX];
int fx[]={0,0,-1,1};
int fy[]={1,-1,0,0};
int m;

//vector<pi>vec;
int dist[MX][MX];
bool visited[MX][MX];

void bfs(int rx,int ry)
{
    queue<pi>q;
    dist[rx][ry]=1;
    q.push(pi(rx,ry));
    visited[rx][ry]=true;
    while(!q.empty()){
        pi top=q.front();
        q.pop();
        //if(dist[top.first][top.second]>m){
            //m=dist[top.first][top.second];
            //cout<<m<<endl;
        //}

        FOR(k,4)
        {
            int tx=top.first+fx[k];
            int ty=top.second+fy[k];
            //cout<<tx<<" "<<ty<<endl;
            //cout<<"Extra"<<x<<" "<<y<<endl;
            //cout<<cost[tx][ty]<<endl;
            if(tx>=0 && tx<x && ty>=0 && ty<y && cost[tx][ty]=='.'&& visited[tx][ty]==false){
                dist[tx][ty]=dist[top.first][top.second]+1;
                //cout<<dist[tx][ty]<<endl;
                //cout<<"dukse"<<endl;
                visited[tx][ty]=true;
                m=dist[tx][ty];
                q.push(pi(tx,ty));
                countd++;
                //cout<<q.size()<<" "<<m<<endl;
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
        //int x,y;
        m=0;
        countd=0;
        mem(visited,false);
        mem(cost,'$');
        mem(dist,0);
        int rx,ry;
        cin>>x>>y;
        swap(x,y);
        FOR(i,x)
            FOR(j,y){
                cin>>cost[i][j];
                if(cost[i][j]=='@')
                    rx=i,ry=j;
            }
        //cout<<rx<<" "<<ry<<endl;

        bfs(rx,ry);

        //cout<<m<<endl;
        cout<<"Case "<<caseno++<<": "<<countd+1<<endl;

    }
}
