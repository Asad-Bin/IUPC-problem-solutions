// . . . Bismillahir Rahmanir Rahim . . .
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg_out cout
#define debug(...) dbg_out << "DBG )> "; __f(#__VA_ARGS__, __VA_ARGS__);
template<typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2> pr) { out << "{ " << pr.first << ", " << pr.second << " }"; return out; }
template<typename T1> ostream& operator<<(ostream& out, vector<T1> vec) { out << "{ "; for (auto &x: vec) out << x << ", "; out << "}"; return out; }
template<typename T1, size_t size> ostream& operator<<(ostream& out, array<T1, size> arr) { out << "{ "; for (auto &x: arr) out << x << ", "; out << "}"; return out; }
template<typename T1, typename T2> ostream& operator<<(ostream& out, map<T1, T2> mp) { out << "{ ";for (auto &x: mp) out << x.first << ": " << x.second <<  ", "; out << "}"; return out; }
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { while (isspace(name[0])) name++; (isalpha(name[0]) || name[0] == '_') ? dbg_out << name << ": " << arg1 << "\n" : dbg_out << arg1 << "\n"; dbg_out.flush();}
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) { const char *comma = strchr(names + 1, ','); while (isspace(names[0])) names++; (isalpha(names[0]) || names[0] == '_') ? dbg_out.write(names, comma - names) << ": " << arg1 << " | " : dbg_out << arg1 << " | "; __f(comma + 1, args...);}
#else
#define debug(...)
#endif
 
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b,ll mod){ if(b==0){ return 1;} ll tm=bigmod(a,b/2,mod); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}



const int N = 1e5;
const ll inf = 1e18+7;
vector<ll> ara[N+5], cost(N+5), child(N+5);
ll dp[N+5];
ll res = inf;
ll cst[N+5], down[N+5], up[N+5];
int n;

void dfs0(int u, int p)
{
	cost[u] = 0;
	child[u] = 1;
	
	for(int K = 0; K < (int)ara[u].size(); K++){
		if(ara[u][K] != p){
			dfs0(ara[u][K], u);
			child[u] += child[ara[u][K]];
			cst[u] += cost[ara[u][K]];
		}
	}
	cost[u] = cst[u] + child[u];
	down[u] = cst[u];
	
	for(auto v:ara[u]) if(v != p) down[u] = min(down[u], down[v] + cst[u] - cost[v]);
	// down[v] -> best result in subtree of v;
	dp[u] = down[u];
	
	vector<ll> vec;
	for(auto v:ara[u]) if(v != p) vec.push_back(down[v] - cost[v]);
	sort(vec.begin(), vec.end());
	
	if((int)vec.size() >= 2) dp[u] = vec[0] + vec[1] + cst[u];
	
	//cout << u << ' ' << child[u] << ' ' << cost[u] << "\n";
}
void dfs2(int u, int p, ll upper)
{
	for(auto v:ara[u]){
		if(v != p){
			up[v] = cst[u] - cost[v] + up[u] + n - child[v];
			dfs2(v, u, down[u]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	int t; cin >> t;
	for(int cs = 1; cs <= t; cs++){
		cin >> n;
		
		for(int K = 1; K <= n; K++) ara[K].clear(), cst[K] = 0, dp[K] = 0, down[K] = 0, up[K] = 0;
		res = inf;
		for(int K = 1; K < n; K++){
			int a, b; cin >> a >> b;
			
			ara[a].push_back(b);
			ara[b].push_back(a);
		}
		
		dfs0(1, 1);
		//dfs1(1, 1, 0, 0);
		dfs2(1, 1, inf);
		
		for(int K = 1; K <= n; K++) res = min(res, min(dp[K], down[K])+up[K]);
		
		cout << "Case " << cs << ": " << res << "\n";
	}
	
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
