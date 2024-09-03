// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';


const ll mod = 993344777;
const int MX = 1e6;

int ara[MX+6];
ll dp[65][(1<<17)+5][2];

int mark[100];

vector<int> primes;
ll calc(int at, int mask, int f)
{
	if(at == 61){
		if(!mask){
			if(f) return 0;
			return 1;
		}
		else{
			if(f) return 1;
			return 0;
		}
	}
	
	if(dp[at][mask][f] != -1LL) return dp[at][mask][f];
	
	ll ans = 0;
	
	if(mark[at]){
		int x = mask, y = at;
		
		for(int K = 0; y > 1 && K < (int)primes.size(); K++){
			if(y%primes[K] == 0){
				while(y%primes[K] == 0){
					y /= primes[K];
					x ^= (1<<K);
				}
			}
		}
		
		ans += mark[at]*calc(at+1, x, f^1);
	}
	
	ans += calc(at+1, mask, f);
	
	return dp[at][mask][f] = ans%mod;
}
int main()
{
	int n;
	
	for(int K = 2; K <= 60; K++){
		bool ok = 1;
		for(int L = 2; L*L <= K; L++) if(K%L == 0) ok = 0;
		if(ok) primes.push_back(K); 
	}
	
	cin >> n;
	
	for(int K = 0; K < n; K++){
		cin >> ara[K];
		mark[ara[K]]++;
	}
	
	memset(dp, -1LL, sizeof dp);
	cout << (calc(1, 0, 0)-1+mod)%mod << "\n";
	
	return 0;
}




























