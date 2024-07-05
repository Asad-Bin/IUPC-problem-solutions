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


const int N = 500;
vector<int> edge[N+5];
int vis[N+5];

int dfs(int u)
{
	int cnt = 0;
	vis[u] = 1;
	for(auto v : edge[u]){
		if(!vis[v]) cnt += dfs(v);
	}
	
	return cnt + 1;
}
int main()
{
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		
		char s[n][n+5];
		for(int K = 0; K < n; K++) scanf("%s", s[K]);
		
		int ara[n+1][n+1];
		for(int K = 1; K <= n; K++) {
			for(int L = 1; L <= n; L++) ara[K][L] = s[K-1][L-1] - '0';
		}
		
		vector<pair<int, int> > v;
		int cnt[n+1][n+1] = {0};
		for(int L = 1; L <= n; L++){
			for(int K = 1; K <= n; K++){
				for(int M = K+1; M <= n; M++){
					//if(K == L || M == L) continue;
					
					if((ara[K][L] + ara[L][M])%2 == ara[K][M]){
						if(ara[K][L] && !cnt[K][L]){
							v.push_back({K, L});
							cnt[K][L]++;
							cnt[L][K]++;
						}
						if(ara[L][M] && !cnt[L][M]){
							v.push_back({L, M});
							cnt[L][M]++;
							cnt[M][L]++;
						}
						if(ara[K][M] && !cnt[K][M]){
							v.push_back({K, M});
							cnt[K][M]++;
							cnt[M][K]++;
						}
					}
				}
			}
		}
		
		for(int K = 1; K <= n; K++) edge[K].clear();
		memset(vis, 0, sizeof vis);
		for(auto it: v){
			edge[it.first].push_back(it.second);
			edge[it.second].push_back(it.first);
		}
		
		bool ok = 1;
		for(int K = 1; K <= n; K++){
			queue<int> q;
			q.push(K);
			int dist[n+1];
			memset(dist, -1, sizeof dist);
			dist[K] = 0;
			
			while(!q.empty()){
				int u = q.front();
				q.pop();
				
				for(auto it: edge[u]){
					if(dist[it] == -1){
						dist[it] = dist[u] + 1;
						q.push(it);
					}
				}
			}
			
			for(int L = 1; L <= n; L++){
				if(dist[L]%2 != ara[K][L]) ok = 0;
			}
			if(!ok) break;
		}
		if(!ok){
			cout << "NO\n";
			continue;
		}
		
		int x = dfs(1);
		
		if(x != n){
			printf("NO\n");
			continue;
		}
		
		printf("YES\n");
		printf("%d\n",  (int)v.size());
		for(auto it : v) printf("%d %d\n", it.first, it.second);
	}
	
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
