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


const int N = 5000;
const int R = 300;
const ll inf = 1e18+7;

ll ara[N+5];
ll pre[N+5], pre2[N+5];
ll post[N+5], post2[N+5];
ll dp[N+5][R+5];
int n, r;

ll calc(int at, int rem)
{
	if(rem == 0) return 0;
	if(at == n-1) return inf;
	
	if(dp[at][rem] != -1ll) return dp[at][rem];
	
	ll ans = inf;
	for(ll K = at+1; K-at-1 <= rem && K < n; K++){
		ll mid = (K + at+1)/2;
		//if(at == -1) mid = 0;
		
		ans = min(ans, calc(K, rem-(K-at-1)) + (pre2[K] - (K-mid) * pre[mid] - pre2[mid]) + (post2[at+1] - (mid - at-1) * post[mid] - post2[mid]));
	}
	
	dp[at][rem] = ans;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		cin >> n >> r;
		
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		if(r >= n){
			cout << -1 << "\n";
			continue;
		}
		
		pre[0] = post[n-1] = 0;
		for(int K = 1; K < n; K++) pre[K] = ara[K]-ara[K-1];
		for(int K = n-2; K >= 0; K--) post[K] = ara[K+1] - ara[K];
		
		for(int K = 1; K < n; K++) pre[K] += pre[K-1];
		for(int K = n-2; K >= 0; K--) post[K] += post[K+1];
		
		pre2[0] = pre[0];
		post2[n-1] = post[n-1];
		for(int K = 1; K < n; K++) pre2[K] = pre[K] + pre2[K-1];
		for(int K = n-2; K >= 0; K--) post2[K] = post[K] + post2[K+1];
		
		//for(int K = 0; K < n; K++) cout << pre[K] << ' ';
		//cout << "\n";
		//for(int K = 0; K < n; K++) cout << pre2[K] << ' ';
		//cout << "\n";
		//for(int K = 0; K < n; K++) cout << post[K] << ' ';
		//cout << "\n";
		//for(int K = 0; K < n; K++) cout << post2[K] << ' ';
		//cout << "\n";
		
		memset(dp, -1ll, sizeof dp);
		
		ll ans = inf;
		for(int K = 0; K <= r && K < n; K++){
			ans = min(ans, calc(K, r-K) + pre2[K]);
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
 
 
 
 
 
 
