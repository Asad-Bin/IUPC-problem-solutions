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



const int N = 1e4;
string s, r, f, rf;
ll n, one;
ll a[4][N+5];

ll calc(ll i, ll level, ll len)
{
	if(i == 0) return 0;
	
	if(level){
		if(len * n <= i){
			return calc(i-len*n, level^1, len*3) + ((len+1)/2)*one + (len/2)*(n-one);
		}
		else{
			ll mid = i/n;
			
			ll ans = 0;
			ans = (mid + 1)/2 * one + mid/2 * (n-one);
			
			i -= n*mid;
			
			if(mid&1){
				if(i) ans += a[2][min(i-1, n-1)];
			}
			else{
				if(i) ans += a[1][min(i-1, n-1)];
			}
			
			return ans;
		}
	}
	else{
		if(len * n <= i){
			return calc(i-len*n, level^1, len*3) + ((len+1)/2)*one + (len/2)*(n-one);
		}
		else{
			ll mid = i/n;
			
			ll ans = 0;
			ans = (mid + 1)/2 * one + mid/2 * (n-one);
			
			i -= n*mid;
			
			if(mid&1){
				if(i) ans += a[3][min(i-1, n-1)];
			}
			else{
				if(i) ans += a[0][min(i-1, n-1)];
			}
			
			return ans;
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
		cout << "Case " << cs << ":\n";
		
		cin >> s;
		n = (int)s.length();
		one = 0;
		for(int K = 0; K < n; K++) if(s[K] == '1') one++;
		
		//cout << "one = " << one << "\n";
		
		r = s;
		reverse(r.begin(), r.end());
		
		f.assign((int)s.length(), '0');
		for(int K = 0; K < (int)s.length(); K++) f[K] = (s[K] == '0' ? '1' : '0');
		
		rf = f;
		reverse(rf.begin(), rf.end());
		
		for(int K = 0; K < n; K++){
			if(s[K] == '0') a[0][K] = 0;
			else a[0][K] = 1;
			
			if(r[K] == '0') a[1][K] = 0;
			else a[1][K] = 1;
			
			if(f[K] == '0') a[2][K] = 0;
			else a[2][K] = 1;
			
			if(rf[K] == '0') a[3][K] = 0;
			else a[3][K] = 1;
		}
		
		for(int K = 1; K < n; K++){
			for(int L = 0; L < 4; L++) a[L][K] += a[L][K-1];
		}
		
		
		int q; cin >> q;
		while(q--){
			ll i, j; cin >> i >> j;
			
			ll len = 1, lvl = 0;
			
			while(len*n < i){
				i -= len * n;
				j -= len * n;
				
				len *= 3;
				lvl ^= 1;
			}
			
			ll x = calc(j, lvl, len);
			ll y = calc(i-1, lvl, len);
			
			cout << x-y << "\n";
		}
	}
	
	return 0;
}




































