#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int MX = 5e4;
int a[5*MX+5], b[5*MX+5], tree[20*MX+5];
vector<int> v[MX+5];

int query(int at, int l, int r, int L, int R)
{
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return tree[at];

    int mid = (l+r)/2;

    int ans = 0;

    ans = query(at*2, l, mid, L, R);
    ans = max(ans, query(at*2+1, mid+1, r, L, R));

    return ans;
}
void update(int at, int l, int r, int idx, int val)
{
    if(l == r){
        tree[at] = val;
        return;
    }

    int mid = (l+r)/2;

    if(idx <= mid) update(at*2, l, mid, idx, val);
    else update(at*2+1, mid+1, r, idx, val);

    tree[at] = max(tree[at*2], tree[at*2+1]);
}
int main()
{
    int t, n, c, d, cs = 0;

    cin >> t;
    while(++cs <= t){
        cin  >> n;

        for(int K = 1; K <= n; K++) v[K].clear();

        for(int K = 1; K <= n; K++){
            cin >> a[K];
            v[a[K]].push_back(K);
        }
        for(int K = 1; K <= n; K++) cin >> b[K];

        cin >> c >> d;

        for(int K = 1; K < c; K++){
            for(int L = 1; L <= n; L++){
                a[K*n+L] = a[L];
                v[a[L]].push_back(K*n+L);
            }
        }
        for(int K = 1; K < d; K++){
            for(int L = 1; L <= n; L++) b[K*n+L] = b[L];
        }

        memset(tree, 0, sizeof tree);

        for(int K = d*n; K > 0; K--){
            for(int L = 0; L < c; L++){
                int x = query(1, 1, c*n, v[b[K]][L]+1, c*n);
                update(1, 1, c*n, v[b[K]][L], x+1);
            }
        }

        //for(int K = 1; K <= c*n; K++) cout << data[K] << ' ';
        //cout << "\n";
        cout << "Case " << cs << ": " << query(1, 1, c*n, 1, c*n) << "\n";
    }

    return 0;
}




