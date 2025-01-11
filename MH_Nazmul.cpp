// MH_Nazmul
// Let it be as simple
#include <bits/stdc++.h>
using namespace std;
//=====================================Definition==============================
const int M = 1e9 + 7;
const int N = 2e5 + 10;
#define pb push_back #define int long long int #define fi first
#define sc second #define nl cout << '\n'
#define all(x) x.begin(), x.end() #define allr(x) x.rbegin(), x.rend()
#define cin(vec, n)             \
    for (int i = 0; i < n; i++) \
    cin >> vec[i];
#define efficient()               \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
int dy[] = {0, 0, -1, +1, +1, -1, +1, -1};
//=====================================LETS BEGIN==============================
void MH(void) {}
signed main()
{ // cout << fixed << showpoint << setprecision(0);
    efficient();
    int t = 1, Test; // cin >> t;
    for (Test = 1; Test <= t; Test++)
    { // cout << "Case " << Test << ": ";
        MH();
    }
    return 0;
}
/* freopen("input.txt", "r", stdin ); freopen("output.txt","w", stdout); */


// NUMBER THEORY  "SIEVE"
int lim = 1e6; vector<bool> check(lim + 1); vector<int> siv;
void sieve()
{ for (int i = 2; i  <= lim; i++)
  { if (check[i] == false)
    { siv.push_back(i);
      for (int j = i * i; j <= lim; j += i)
        check[j] = true;
} } }

// "MODULAR ARITHMETIC"
inline int bigMod(int a, int b, int M)
{  int res = 1;
     while (b > 0) {
          if (b & 1LL) res = (res * a) % M;
          a = (a * a) % M;
          b >>= 1LL;
     } return res;
}
inline int fermats_inverse(int a, int M) { return bigMod(a, M - 2, M); } 

//prime factor
for (int i = 2; i * i <= n;i++){
if(n%i==0){
while (n%i==0){v.push_back(i);n = n / i;}}}

// LIS
//Longest Increasing Subsequence(LIS)
const int N = 1e3 + 9; int dp[N]; void solve(int test) {
//LIS = longest increasing Subsequence
int n; cin>>n; int a[n]; cin(a,n); for (int i = 0; i < n;i++){
for (int j = 0; j < i;j++){ if(a[j]<a[i]){ dp[i] = max(dp[j], dp[i]);
} } dp[i]++; } /* O(n*n) */ int length = 0;
for (int i = 0; i < n;i++){ length = max(length, dp[i]); }
cout << length << "\n"; }

//BIT MANIPULATION
int getBit(int n,int i){ return (n & (1 << i)); }
int setBit(int n,int i) { return (n | (1 << i));}
int clearBit(int n,int i){ return (n & ~(1 << i));}
int updateBit(int n,int i,int value){ n = clearBit(n, i);
return (n | (value << i)); }

//KADAN'S ALGORITHM
int sum = 0, ma = -1e9;
for (ll j = 0; j < n; j++)
{ 
    sum = max(sum + v[j], v[j]); ma = max(ma, sum);
}

//ALL POSSIBLE SUBSTRING
ll All_Possible_Substring_Sum(string s) { int n = (int)s.size();
vector<ll> digit_sum(n); digit_sum[0] = s[0] - '0';
ll totalSum = digit_sum[0]; for (int i = 1; i < n; i++) {
int cur_val = s[i] - '0'; 
digit_sum[i] = (i + 1) * cur_val + 10 * digit_sum[i - 1];
totalSum += digit_sum[i]; }
return totalSum; // TC: O(N) 
}

// nPr  all permutation of r numbers elements from n numbers {'ab'='ba'}
int nPr(int n, int r, int mod) { // O(log(MOD))
if (r > n) return -1; int numerator = fact[n] % mod;
int denominator = fact[n - r] % mod;
numerator = (numerator * bigMod(denominator, mod - 2,
mod)) % mod; return numerator; }

// nCr all combination of r numbers from numbers elements {'ab'!='ba'}
int nCr(int n, int r, int mod) { // O(log(MOD))
if (r == 0) return 1;if (r > n) return -1;
int numerator = fact[n] % mod;
int denominator = (fact[n - r] * fact[r]) % mod;
numerator = (numerator * bigMod(denominator, mod - 2,mod)) % mod;
return numerator; }

//STRING HASHING
//FULL STRING
int build_hash(string s, vector<int> &pw, int p, int mod) {
    int n = s.size();
    int hash = 0;
    pw[0] = 1;
    for (int i = 0; i < n; i++)
    {
        pw[i] = (pw[i - 1] * p) % mod;
        hash = (hash + ((s[i] - 'a' + 1) * pw[i]) % mod) % mod;
    }
    return hash; }

// SUBSTRING HASH AND WITHOUT SUBSTRING HASH
void build_hash_table(string s, vector<int> &table, vector<int> &pw, int p, int mod)
{
    int n = s.size();
    table[0] = s[0] - 'a' + 1;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = (pw[i - 1] * p) % mod;
        pwi[i] = fermats_inverse(pw[i], M);
        table[i] = (table[i - 1] + (pw[i] * (s[i] - 'a' + 1)) % mod) % mod;
        // cout << "table["<<i<<"=" << table[i] << " ";
    }
}
int get_substring_hash(int l, int r, const vector<int> table, const vector<int> pwi, int mod)
{
    int hash_value = table[r];
    // cout << "hash_val= " << table[r] << " ";
    if (l > 0)
    {
        hash_value = (((hash_value - table[l - 1] + mod) % mod) * pwi[r - l + 1]) % mod;
    }
    return hash_value;
}
int get_string_hash_without_substring(int sub_l, int sub_r, int string_size, vector<int> &hash_table)
{
    int mod = M;
    int left_part = 0;
    if (sub_l > 0)
        left_part = hash_table[sub_l - 1];
    int right_part = (((hash_table[string_size - 1] - hash_table[sub_r] + mod) % mod) * pwi[sub_r - sub_l + 1]) % mod;
    return (left_part + right_part) % mod;
}

// DATA STRUCTURE
// POLICY BASED DATA STRUCTURE
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> // o_set<ll> st;  st.order_of_key(x);
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//PRIMS ALGORITHM TO FIND MINIMUS SPANNIG TREE
void prims_cal(vector<vector<pair<int, int>>> &graph)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> vis(N, false);
    pair<int, int> zero = {0, 1};
    pq.push(zero);
    int node, weight, total_cost = 0;
    while (!pq.empty())
    {
        node = pq.top().second;
        weight = pq.top().first;
       
        pq.pop();
        if (vis[node] == true)
            continue;

        vis[node] = true;
        total_cost += weight;
        for (auto it : graph[node])
        {
            if (vis[it.first])
                continue;
            pq.push({it.second, it.first});
        }
       
    }
    cout << total_cost;
}

//KRUSKAL ALGOTIHM TO FIND MINIMUM SPANNING TREE
class DisjointSet
{
    vector<int> par, rank;

public:
    DisjointSet(int n)
    {
        par.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
        }
    }
    int find_parent(int node)
    {
        if (node == par[node])
            return node;
        else
            return par[node] = find_parent(par[node]);
    }
    void union_by_rank(int u, int v)
    {
        int ult_u = find_parent(u);
        int ult_v = find_parent(v);
        if (ult_u == ult_v)
            return;
        else if (rank[ult_u] < rank[ult_v])
        {
            par[ult_u] = ult_v;
        }
        else if (rank[ult_u] > rank[ult_v])
        {
            par[ult_v] = ult_u;
        }
        else
        {
            par[ult_u] = ult_v;
            rank[ult_v]++;
        }
    }
};

void solve(void)
{
    int node, edge, total_cost = 0;
    cin >> node >> edge;
    DisjointSet s(node + 5);
    vector<pair<int, pair<int, int>>> st;
    for (int i = 0; i < edge; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        st.pb({w, {v1, v2}});
    }
    sort(all(st));
    // for(auto it: st)cout <<it.first<< it.second.first<<it.second.first<<"\n";

    for (int i = 0; i < edge; i++)
    {
        if (s.find_parent(st[i].second.first) == s.find_parent(st[i].second.second))
            continue;
        s.union_by_rank(st[i].second.first, st[i].second.second);
        total_cost += st[i].first;
    }
    cout << total_cost;
}

//WARSHAL ALGORITHM FOR ALL PAIR SHORTEST PATH
 
void solve(void)
{
    int n, m, q;
    cin >> n >> m >> q;
 
    vector<vector<int>> p(n + 1, vector<int>(n + 1, INF));
 
    for (int i = 0; i < m; i++)
    {
        int u, v, e;
        cin >> u >> v >> e;
 
        p[u][v] = min(p[u][v], e);
        p[v][u] = min(p[v][u], e);
    }
 
    for (int i = 1; i <= n; i++)
    {
        p[i][i] = 0;
    }
 
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[i][k] < INF && p[k][j] < INF)
                {
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
                }
            }
        }
    }
 
    while (q--)
    {
        int u, v;
        cin >> u >> v;
 
        if (p[u][v] == INF)
            cout << -1 << "\n";
        else
            cout << p[u][v] << "\n";
    }
}


// DIJKSTRA'S ALGORITHM   SINGLE SOURCE SHORTEST PATH
void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dis[start] = 0;
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        for (auto child : graph[node])
        {
            int to_dis = child.first;
            int to_node = child.second;
            if (vis[to_node] == 1)
                continue;
            if (dis[to_node] >= to_dis + dis[node])
            {
                dis[to_node] = to_dis + dis[node];
                pq.push({dis[to_node], to_node});
            }
        }
    }
}

// BELLMANFORD ALGORITHM TO FIND SINGLE SOURCE SHORTEST PATH AND NEG CYCLE
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

//TOPOLOGICAL SORT
/*kono akta kajer scheduling korara jonno directed graph a use 
kora hoy.kon kajta kontar age asbeseta.*/
int indegree[N];
void toposort(){
int n = 4;
for (int i = 1; i <= n;i++){//m porjonto hoy
int u, v;
cin >> u >> v;//u theke v te jabe
g[u].push_back(v);
indegree[v]++;
} vector<int> z;
for (int i = 1; i <= n;i++){
if(indegree[i]==0){
z.push_back(i);
vis[i] = true;
}
}vector<int> ans;
while (ans.size()<n){
if(z.size()==0){
cout << "IMPOSSIBLE\n";
return;
}
int u = z.back(); // atar jonno O(V+E);
z.pop_back();
ans.push_back(u);
vis[u] = true;
for(auto x : g[u]){
indegree[x]--;
// porer indegree zero hobe asob ar modde dia e
// karon arai komche
if(!vis[x] and indegree[x]==0){
z.push_back(x);
}}}
}
void find_cycle(){
int n, m;
cin >> n >> m;
while(m--){
int u, v;
cin >> u >> v;
gr[u].push_back(v);
}cycle = false;
for (int i = 1; i <= n;i++){
if(col[i]==0){//that means not visited
cycle_dfs(i);}
}if(cycle){yes;}
}


//SEGMENT TREE
// Segment Tree Starts
int lazy[4 * N];
int tree[4 * N];
int arr[N];
void build(int id, int l, int r){
if (l == r){
tree[id] = arr[l];
return;
}
int mid = (l + r) / 2;
build(2 * id , l, mid);
build(2 * id + 1, mid + 1, r);
tree[id] = tree[2 * id ] + tree[2 * id + 1];}
void update_tree(int node, int first_node,
int last_node, int lo_rng, int hi_rng, int val){
if (lazy[node] != 0){
tree[node] += (last_node - first_node + 1) *
lazy[node];
if (first_node != last_node){
lazy[node * 2 ] += lazy[node];
lazy[node * 2 + 1] += lazy[node]; }
lazy[node] = 0; }
if ( first_node > hi_rng || last_node < lo_rng)
return;
if (first_node >= lo_rng && last_node <= hi_rng){
tree[node] += (last_node - first_node + 1) * val;
if (first_node != last_node){
lazy[node * 2 ] += val;
lazy[node * 2 + 1] += val; }
return;
}
int mid = (first_node + last_node) / 2;
update_tree(node * 2 , first_node, mid, lo_rng,
hi_rng, val);
update_tree(node * 2 + 1, mid + 1, last_node, lo_rng,
hi_rng, val);
tree[node] = tree[node * 2 ] + tree[node * 2 + 1];
}
int rangeSum(int node, int first_node, int last_node,
int lo_rng, int hi_rng)
{
if (lazy[node] != 0) {
tree[node] += (last_node - first_node + 1) *
lazy[node];
if (first_node != last_node){
lazy[node * 2 ] += lazy[node];
lazy[node * 2 + 1] += lazy[node]; }
lazy[node] = 0; }
if (first_node>hi_rng || last_node<lo_rng)return 0;
if (first_node >= lo_rng && last_node <= hi_rng)
return tree[node];
int mid = (first_node + last_node) / 2;
return rangeSum(node * 2 , first_node, mid, lo_rng,
hi_rng) + rangeSum(node * 2 + 1, mid + 1, last_node,
lo_rng, hi_rng);
}
void solve(void){
int n, q, flag, l, r, val, ans;
cin >> n >> q;
for (int i = 1; i <= n; i++)
cin >> arr[i];
build(1, 1, n);
//for(int i =0;i<20;i++)cout<<tree[i]<<"";
cout<<endl;
while (q--){
cin >> flag;
if (flag == 1){
cin >> l >> val;
update_tree(1, 1, n , l, l, val); }
else{
cin >> l >> r;
ans = rangeSum(1, 1, n, l, r);
cout << ans << "\n";
}}
}