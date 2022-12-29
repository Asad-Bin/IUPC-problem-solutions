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
 

bool cmp(pair<int, int > a, pair<int, int > b){
	return a.first > b.first;
}
const int N = 100;
const int MX = 1e5;
const int M = 1e5;
int n, m;
ll a[N+5], b[N+5], c[M+5], d[M+5];
vector<pair<ll, ll> > st, v;
ll dp[N+5][N+5][N+5];
ll calc(int at, ll mx, int cnt)
{
	if(at == n){
		ll ans = 0;
		
		if(mx == -1) mx = MX;
		else mx = st[mx].first;
		
		for(auto [i, l]: v){
			if(mx == 0) break;
			
			if(l >= cnt){
				ans += i;
				mx--;
			}
		}
		
		return ans;
	}
	
	if(mx != -1 && dp[at][mx][cnt] != -1) return dp[at][mx][cnt];
	
	ll ans = calc(at+1, mx, cnt);
	ans = max(ans, calc(at+1, at, cnt+1)+st[at].second);
	
	if(mx == -1) return ans;
	return dp[at][mx][cnt] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	cin >> n;
	for(int K = 0; K < n; K++) cin >> a[K];
	for(int K = 0; K < n; K++) cin >> b[K];
	
	for(int K = 0; K < n; K++){
		st.push_back({b[K], a[K]});
	}
	sort(st.begin(), st.end(), cmp);
	
	cin >> m;
	for(int K = 0; K < m; K++) cin >> c[K];
	for(int K = 0; K < m; K++) cin >> d[K];
	
	for(int K = 0; K < m; K++){
		v.push_back({c[K], d[K]});
	}
	sort(v.begin(), v.end(), cmp);
	
	memset(dp, -1ll, sizeof dp);
	
	cout << calc(0, -1, 0) << "\n";
	
	
	
	return 0;
}
