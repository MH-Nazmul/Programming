// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
const int N = 2e5+10;
const int M = 1e9+7;
const int INF=1e18;
struct edge{
    int u,v,weight;
};
int NODE,EDGE;
vector<int>dis(N,INF);
void bellmanford(int source,vector<edge>graph){
    dis[source]=0;

    for(int i=1;i<NODE;i++)
    {
        for(int j=1;j<=EDGE;j++){
            int u=graph[j].u;
            int v=graph[j].v;
            int w=graph[j].weight;
            if(dis[u]!=INF and dis[u]+w<dis[v])
              dis[v]=dis[u]+w;
        }
    }

    //lets find if there is a negative cycle
    bool negativecyle=false;
    for (int j = 1; j <= EDGE; j++)
    {
        int u = graph[j].u;
        int v = graph[j].v;
        int w = graph[j].weight;
        if (dis[u] != INF and dis[u] + w < dis[v])
            {
                negativecyle=true;
                break;
            }
    }
    if(negativecyle){cout<<"negative cycle exist";return;}
    for(int i=1;i<=NODE;i++){
        cout<<"distance from node :"<<source<<" to node :"<<i<<" is :"<<dis[i]<<"\n";
    }
}
void solve(void)
{
    cin>>NODE>>EDGE;
    vector<edge>graph(NODE+5);
    for(int i=1;i<=EDGE;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        graph[i].u=v1;
        graph[i].v=v2;
        graph[i].weight=w;
    }
    int source;
    cin>>source;
    bellmanford(source,graph);
}

signed main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int t=1;
 //cin>>t;
 while (t--)
 solve();
 return 0;
}