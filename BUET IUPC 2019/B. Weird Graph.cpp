#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 1e5;
vector<int> ara[MX+5];
bool vis[MX+5];

const int mod = 1e9+7;

int bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    int cnt = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cnt++;

        for(int K = 0; K < (int)ara[u].size(); K++){
            if(!vis[ara[u][K]]){
                vis[ara[u][K]] = 1;
                q.push(ara[u][K]);
            }
        }
    }

    return cnt;
}

ll bigmod(ll a, ll p, ll M)
{
    p %= (M-1);

    ll ans = 1;
    while(p > 0){
        if(p&1) ans = ans * a % M;

        a = a*a%M;
        p >>= 1LL;
    }

    return ans;
}
ll inverse(ll a, ll M)
{
    if(__gcd(a, M) == 1) return bigmod(a, M-2, M)%M;

    return 1;
}

ll ncr(ll n, ll r)
{
    r = min(r, n-r);
    ll ans = 1;

    for(int K = 1; K <= r; K++){
        ans = (ans*n%mod);
        n--;
        ans = ans*inverse(K, mod)%mod;
    }

    return ans;
}

int main()
{
    int n, m;
    int a, b;

    cin >> n >> m;

    for(int K = 0; K < m; K++){
        cin >> a >> b;
        ara[a].push_back(b);
        ara[b].push_back(a);
    }

    int l = n;
    ll ans = 1;
    for(int K = 1; K <= n; K++){
        if(!vis[K]){
            int x = bfs(K);
            ans = ans*ncr(l, x)%mod;
            l -= x;

            //cout << x << ' ' << l << ' ' << ans << "\n";
        }
    }
    cout << ans << "\n";

    return 0;
}


