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


const int N = 2e5;
string a, b; 
ll tree[2][4*N+5][26], lazy[2][4*N+5];

void build(ll at, ll l, ll r, ll typ)
{
	if(r < l) return;
	lazy[typ][at] = -1;
	if(l == r){
		for(int K = 0; K < 26; K++) tree[typ][at][K] = 0;
		
		if(typ == 0) tree[typ][at][a[l-1]-'a']++;
		else tree[typ][at][b[l-1]-'a']++;
		
		return ;
	}
	
	ll mid = (l + r) / 2;
	
	build(at*2, l, mid, typ);
	build(at*2+1, mid+1, r, typ);
	
	for(int K = 0; K < 26; K++) tree[typ][at][K] = tree[typ][at*2][K] + tree[typ][at*2+1][K];
}

void prop(ll at, ll l, ll r, ll typ)
{
	if(lazy[typ][at] == -1) return;
	
	for(int K = 0; K < 26; K++) tree[typ][at][K] = 0;
	tree[typ][at][lazy[typ][at]] = r-l+1;
	
	if(l != r){
		lazy[typ][at*2] = lazy[typ][at*2+1] = lazy[typ][at];
	}
	
	lazy[typ][at] = -1;
}

void update(ll at, ll l, ll r, ll L, ll R, char c, ll typ)
{
	prop(at, l, r, typ);
	
	if(r < l || R < l || r < L) return;
	if(L <= l && r <= R){
		lazy[typ][at] = c-'a';
		prop(at, l, r, typ);
		lazy[typ][at] = -1;
		
		return;
	}
	
	
	ll mid = (l + r) / 2;
	
	update(at*2, l, mid, L, R, c, typ);
	update(at*2+1, mid+1, r, L, R, c, typ);
	
	for(int K = 0; K < 26; K++) tree[typ][at][K] = tree[typ][at*2][K] + tree[typ][at*2+1][K];
}
ll sol[2][26];
void query(ll at, ll l, ll r, ll L, ll R, ll typ)
{
	prop(at, l, r, typ);
	
	if(r < l || R < l || r < L) return;
	if(L <= l && r <= R){
		for(int K = 0; K < 26; K++) sol[typ][K] += tree[typ][at][K];
		return ;
	}
	
	ll mid = (l + r) / 2;
	
	query(at*2, l, mid, L, R, typ);
	query(at*2+1, mid+1, r, L, R, typ);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	int T; cin >> T;
	while(T--){
		cin >> a >> b;
		
		ll n = (ll)a.length();
		ll m = (ll)b.length();
		
		build(1, 1, n, 0);
		build(1, 1, m, 1);
		
		ll q; cin >> q;
		while(q--){
			ll t; cin >> t;
			
			if(t == 1){
				ll l, r; char c; cin >> l >> r >> c;
				if(r < l) swap(l, r);
				
				update(1, 1, n, l, r, c, 0);
			}
			else if(t == 2){
				ll l, r; char c; cin >> l >> r >> c;
				if(r < l) swap(l, r);
				
				update(1, 1, m, l, r, c, 1);
			}
			else{
				memset(sol, 0ll, sizeof sol);
				
				ll l, r; cin >> l >> r;
				if(r < l) swap(l, r);
				ll ans = (r-l+2);
				query(1, 1, n, l, r, 0);
				
				cin >> l >> r;
				if(r < l) swap(l, r);
				ans *= (r-l+2);
				query(1, 1, m, l, r, 1);
				
				for(ll K = 0; K < 26; K++) ans -= sol[0][K]*sol[1][K];
				
				cout << ans << "\n";
			}
		}
	}
	
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
