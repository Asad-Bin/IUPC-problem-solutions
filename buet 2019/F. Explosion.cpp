#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 1e4;
vector<int> ara[MX+5];
int n;

int bfs(int s, int d)
{
    vector<int> level(n+1, -1);
    queue<int> q;
    q.push(s);
    level[s] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int K = 0; K < (int)ara[u].size(); K++){
            if(level[ara[u][K]] == -1){
                level[ara[u][K]] = level[u]+1;
                q.push(ara[u][K]);

                if(ara[u][K] == d) return level[ara[u][K]]-1;
            }
        }
    }

    return 1;
}
ll gcd(ll x, ll y)
{
    return y==0 ? x : gcd(y, x%y);
}
int main()
{
    int t, r, p, a, b;

    cin >> t;
    while(t--){
        cin >> n >> r >> p;

        for(int K = 1; K <= n; K++) ara[K].clear();
        for(int K = 1; K < n; K++){
            cin >> a >> b;
            ara[a].push_back(b);
            ara[b].push_back(a);
        }

        int x = bfs(r, p);

        if(x%2==0){
            cout << 1 << ' ' << 1 << "\n";
            continue;
        }

        int g = gcd(x, n-2);
        cout << x/g << ' ' << (n-2)/g << "\n";
    }

    return 0;
}






